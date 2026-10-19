// Implementacion MD5 y AES
#include <Arduino.h>
#include <string.h>
#include <mbedtls/version.h>
#include <mbedtls/aes.h>
#include <mbedtls/md5.h>

void imprimir_hex(const unsigned char *datos, size_t size_datos){
  for(size_t i=0; i<size_datos; i++){
    Serial.printf("%02x", datos[i]);
  }
  Serial.println();

}

void algorithm_md5(){
  Serial.println("\nAlgoritmo MD5");
  const char *mensaje = "El profe JJ usa whatsapp";
  unsigned char hash[16];
  
  int resultado;

  #if MBEDTLS_VERSION_MAJOR >= 3
    resultado = mbedtls_md5((const unsigned char* )mensaje, strlen(mensaje), hash);
  #else
    resultado = mbedtls_md5_ret((const unsigned char* )mensaje, strlen(mensaje), hash);
  #endif
  
  Serial.print("Mensaje: ");
  Serial.println(mensaje);
  Serial.print("Hash MD5: ");
  imprimir_hex(hash, sizeof(hash));
}

void algorithm_aes(){
  Serial.println("\nAlgoritmo AES");
  unsigned char clave[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  unsigned char mensaje[16] = {'H','o','l','a','M','u','n','d','o','C','r','B','r','o','s','t'}; 
  
  unsigned char cifrado[16];
  unsigned char descifrado[17] = {0};

  mbedtls_aes_context aes;
  mbedtls_aes_init(&aes);

  int r = mbedtls_aes_setkey_enc(&aes, clave, 128);

  if(r == 0) {
    r = mbedtls_aes_crypt_ecb(&aes, MBEDTLS_AES_ENCRYPT, mensaje, cifrado);
  }
  
  Serial.print("Mensaje cifrado (HEX): ");
  imprimir_hex(cifrado, 16);

  r = mbedtls_aes_setkey_enc(&aes, clave, 128);

  if(r == 0){
    r = mbedtls_aes_crypt_ecb(&aes, MBEDTLS_AES_DECRYPT, cifrado, descifrado);
  }

  Serial.print("Mensaje Descifrado: ");
  Serial.println((char*) descifrado);

  mbedtls_aes_free(&aes);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  algorithm_md5();
  algorithm_aes();

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000); // this speeds up the simulation
}
