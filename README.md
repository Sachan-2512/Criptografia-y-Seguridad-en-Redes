# Criptografia-y-Seguridad-en-Redes

##2. Tres incidentes de seguridad en Sistemas Embebidos

###Caso 1. Botnet Mirai (2016): ataque a cámaras IP y routers
En 2016, el malware Mirai infectó numerosos dispositivos IoT, principalmente cámaras IP y routers, aprovechando credenciales predeterminadas. Los dispositivos comprometidos fueron incorporados a una botnet utilizada para lanzar ataques distribuidos de denegación de servicio (DDoS).


El 21 de octubre de 2016, un ataque contra el proveedor DNS Dyn provocó interrupciones en el acceso a numerosos servicios de Internet. Mirai aprovechaba dispositivos expuestos a Internet con contraseñas de fábrica conocidas. 

¿Cómo se podría haber evitado?
- Reemplazando las contraseñas predeterminadas por credenciales únicas y seguras.
- Deshabilitando servicios innecesarios como Telnet.
- Manteniendo actualizado el firmware.
- Evitando la exposición directa de los dispositivos a Internet mediante reglas de firewall.
Vulnerabilidad principal: autenticación débil y credenciales predeterminadas.


###Caso 2. Hackeo del Jeep Cherokee (2015)
En 2015, investigadores de seguridad demostraron que era posible acceder remotamente al sistema de entretenimiento Uconnect de vehículos Jeep Cherokee y manipular funciones del automóvil a través de sus sistemas electrónicos conectados.

La vulnerabilidad permitió demostrar riesgos sobre sistemas de control del vehículo. Como consecuencia, Fiat Chrysler inició una campaña de actualización de aproximadamente 1,4 millones de vehículos. La investigación de la NHTSA documentó el ataque como una demostración de seguridad y no confirmó ataques maliciosos reales que produjeran esos efectos. 

¿Cómo se podría haber evitado?
- Separando mediante mecanismos de seguridad los sistemas de entretenimiento de los sistemas críticos del vehículo.
- Restringiendo los servicios y puertos accesibles remotamente.
- Aplicando actualizaciones de firmware que corrigieran las vulnerabilidades.
- Realizando pruebas de penetración durante el desarrollo del sistema.
Vulnerabilidad principal: acceso remoto no autorizado y aislamiento insuficiente entre sistemas.

###Caso 3. Vulnerabilidades en marcapasos St. Jude Medical (2017)
En 2017, la FDA estadounidense confirmó vulnerabilidades de ciberseguridad en determinados marcapasos de St. Jude Medical, posteriormente adquirida por Abbott. Estas vulnerabilidades podían permitir que una persona no autorizada accediera al dispositivo mediante comunicaciones de radiofrecuencia.

Un atacante que lograra explotar estas debilidades podría modificar la configuración del marcapasos y afectar su funcionamiento. Se desarrolló una actualización de firmware para reducir estos riesgos. Es importante aclarar que se trató de vulnerabilidades confirmadas, sin informes conocidos de daños a pacientes causados por su explotación. 

¿Cómo se podría haber evitado?
- Implementando mecanismos de autenticación robustos para las comunicaciones inalámbricas.
- Cifrando y protegiendo la integridad de las comunicaciones.
- Impidiendo que dispositivos no autorizados modificaran los parámetros médicos.
- Realizando auditorías de seguridad y proporcionando actualizaciones seguras de firmware.
Vulnerabilidad principal: protección insuficiente del acceso inalámbrico y de la autorización de comandos.
