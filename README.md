 # TRABAJO PRACTICO - MIDDLEWARE
 
Alumno: Jesus Andres Correa Tornero

Padrón: 102310

Link : https://github.com/andy0013/TP3


# Introducción

El trabajo practico consiste en la creacion de un servidor, desde el cual sea posible aceptar varios clientes en paralelo, los cuales podran enviar mensajes para realizar solicitudes respetando un protocolo de comunicacion, debe de haber un manejo correcto de errores, en aquellas situaciones donde por un mensaje mal enviado o la falla de distintas conexiones no se detenga la ejecucion del programa, sino que sepa como manejarlo.

# MODELO


 Para el modelo del servidor nos basamos en el modelo cliente-servidor presentado en la clase, es decir, tenemos un hilo main el cual espera el input corroborando que el ingreso sea q - en ese caso, se cerrara el socketAceptador. 
 Tambien, dentro del servidor, se lanzara un hilo el cual escucha clientes, representado el en Diagrama mostrado previamente, este hilo acepta clientes, y los lanza a correr, estos hilos son la clase ClientesEnUso, estos mismos intercambian informacion con el cliente. 
 Los mismos utilizan una interfaz **Solicitud** para definir que comportamiento utilizaran, para esto hace uso de la clase **StrategySolicitud** y de la clase **Protocolo** en caso de necesitar recibir informacion del cliente, y de tener que enviar informacion al mismo. 
