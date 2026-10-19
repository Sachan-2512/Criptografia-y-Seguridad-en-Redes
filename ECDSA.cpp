// Implementacion Firma Digital
#include <Arduino.h>
#include <string.h>
#include <mbedtls/version.h>
#include <mbedtls/ecdsa.h>
#include <mbedtls/sha256.h>
#include <mbedtls/entropy.h>
#include <mbedtls/ctr_drbg.h>

void firma_digital(){
  Serial.println("\nFirma Digital ECDSA");

  const char *mensaje = "Abandonen Windows, Microsoft debe caer";
  unsigned char hash[32];
  unsigned char firma[160];
  size_t longitud_firma = 0;

  mbedtls_ecdsa_context ecdsa;
  mbedtls_entropy_context entropy;
  mbedtls_ctr_drbg_context drbg;

  mbedtls_ecdsa_init (&ecdsa);
  mbedtls_entropy_init (&entropy);
  mbedtls_ctr_drbg_init (&drbg);

  const char *personalizacion = "ECDSA_LAB";

  int r = mbedtls_ctr_drbg_seed(&drbg, mbedtls_entropy_func, &entropy, (const unsigned char *)personalizacion, strlen(personalizacion));

  // Genero el par de claves
  Serial.println("Generando el par de claves..... ");
  r = mbedtls_ecdsa_genkey(&ecdsa, MBEDTLS_ECP_DP_SECP256R1, mbedtls_ctr_drbg_random, &drbg);
  Serial.println("Clave publica y privada generada.");


  // Hash SHA-256 del mensaje
  #if MBEDTLS_VERSION_MAJOR >= 3
    r = mbedtls_sha256((const unsigned char *)mensaje, strlen(mensaje), hash, 0);
  #else
    r = mbedtls_sha256_ret((const unsigned char *)mensaje, strlen(mensaje), hash, 0);
  #endif

  Serial.print("Mensaje: ");
  Serial.println(mensaje);

  // Firmo hash con la clave privada
  Serial.println("Firmando Mensaje...... ");
  #if MBEDTLS_VERSION_MAJOR >= 3
    r = mbedtls_ecdsa_write_signature(&ecdsa, MBEDTLS_MD_SHA256, hash, sizeof(hash), firma, sizeof(firma), &longitud_firma, mbedtls_ctr_drbg_random, &drbg);
  #else
    r = mbedtls_ecdsa_write_signature(&ecdsa, MBEDTLS_MD_SHA256, hash, sizeof(hash), firma, &longitud_firma, mbedtls_ctr_drbg_random, &drbg);
  #endif
   
  Serial.printf("Firma generada: %u bytes\n",(unsigned)longitud_firma);

  // Verificar firma con la clave publica
  r = mbedtls_ecdsa_read_signature(&ecdsa, hash, sizeof(hash), firma, longitud_firma);

  if (r == 0) {
    Serial.println("Firma valida");
  } else {
    Serial.println("Firma invalida");
  }

  // Busco alterar el hash y volver a verificar
  Serial.println("Prueba con Hash Alterado...");
  hash[0] ^= 0x01;
  r = mbedtls_ecdsa_read_signature(&ecdsa, hash, sizeof(hash), firma, longitud_firma);
  
  if (r != 0) {
    Serial.println("Hash alterado: firma rechazada");
  } else {
    Serial.println("Error: firma aceptada");
  }

  mbedtls_ecdsa_free (&ecdsa);
  mbedtls_entropy_free (&entropy);
  mbedtls_ctr_drbg_free (&drbg);
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  firma_digital();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000); // this speeds up the simulation
}
