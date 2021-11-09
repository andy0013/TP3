 # TRABAJO PRACTICO - MIDDLEWARE
 
Alumno: Jesus Andres Correa Tornero

Padrón: 102310

Link : https://github.com/andy0013/TP3


# Introducción

El trabajo practico consiste en la creacion de un servidor, desde el cual sea posible aceptar varios clientes en paralelo, los cuales podran enviar mensajes para realizar solicitudes respetando un protocolo de comunicacion, debe de haber un manejo correcto de errores, en aquellas situaciones donde por un mensaje mal enviado o la falla de distintas conexiones no se detenga la ejecucion del programa, sino que sepa como manejarlo.

# MODELO

 
 ![model](imagenes/primer-modelo.png)


 Para nuestra implementacion del trabajo practico nos basamos en el modelo cliente-servidor presentado en la clase, es decir, tenemos un hilo main el cual espera el input corroborando que el ingreso sea "q", en la clase **Servidor** ;en ese caso se cerrara el socketAceptador. 
 Tambien, dentro del servidor, se lanzara un hilo el cual escucha clientes **EscucharClientes**, representado el en Diagrama mostrado previamente, este hilo acepta clientes **ClientesEnCurso**, y los lanza a correr, estos mismos intercambian informacion con el cliente.
 
 Los ClientesEnCurso utilizan una interfaz **Solicitud** para definir que comportamiento utilizaran, para esto hace uso de la clase **StrategySolicitud** y de la clase **Protocolo** en caso de necesitar recibir informacion del cliente, y de tener que enviar informacion al mismo. 

Asi mismo, del lado del **Cliente** tambien hacemos uso de la clase **StrategySolicitud** para definir que tipo de informacion se enviara al servidor y al cliente, por lo que, estas clases son de uso compartido, y tienen la logica de lo que se hara en cada caso, del lado del __Cliente__ y del lado del __Servidor__.
