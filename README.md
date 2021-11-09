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


# SECUENCIA SERVIDOR CORRIENDO


 ![model](imagenes/secuencia2.png)


En el primer caso, vemos cuando inicia el ./server. En esta situacion se inicia el hilo que escucha clientes *EscucharClientes*, el mismo realiza un loop en el cual acepta clientes, esta operacion es bloqueante, por lo que esperara a que un cliente intente conectarse. Una vez acepta a un cliente, recibe el SocketCliente y con este Socket, lanza el hilo *CLienteEnCurso* el cual recibe como parametro su Socket y el Monitor de donde se obtendran datos para modificar los mismos.


# SECUENCIA SERVIDOR FIN

 ![model](imagenes/secuencia.png)

En este caso mostramos el flujo de finalizar de los clientes. Podemos ver que cuando se ingresa una "q", el hilo main que estaba esperando el input no realiza llamado a otra funcion mas que a cerrar el socket servidor, luego, continuando su flujo, ya que la misma se encuentra en el main - stack, va a finalizar, pero para esto, debe llamar al destructor de la clase *EscucharClientes*, y este mismo destructor se ocupa de finalizar hilos en curso - liberar memoria, y joinearse a si mismo, antes de destruirse. 


# PROBLEMAS EN DESARROLLO - SITUACIONES PARTICULARES

Si bien, con las explicaciones de clase fue mucho mas sencillo encarar el TP, tuve que realizar un cambio importante al momento de encarar este mismo, ya que, mi forma de trabajar previa con los Thread era a traves de lanzar los hilos con std::thread(clase que tenga metodo Operator()()). Sin embargo, en este caso me era mas sencillo que mis clases implementen la clase Thread, con el metodo run(). Porque?.
De esta forma podria seguir mas claro el ejemplo que vimos en clase para iterar la lista a traves de un metodo booleano al cual puedo acceder y decidir si eliminar el Thread o no. 

De mi forma inicial, tan solo podria acceder a los metodos de la clase Thread - Joinable() - Join() .... Por lo que hacer ese cambio me ayudo bastante, aunque fue algo distinto en un principio.

Por otro lado, el uso de Iterator para moverme en la std::list hizo que me lleve horas de trabajo al no hacer un it.operator++ en un destructor, debido a que era un destructor me fue mas dificil hayar la fuente, asi que me llevo esa leccion al usar esta nueva forma de recorrer una lista sin usar el .size().

Sin embargo, si tuviera que decidir cual fue el area que mas me dio dificultar seria en el entendimiento de en que scope se encuentra la informacion, cuando se destruye, donde se llamaria al destructor. Ya que con el error previamente mencionado : no se hizo it.operator++, me sucedia que el codigo se quedaba destruyendo un objeto eternamente, pero otro hilo estaba intentando joinear, lo que lo hacia mucho mas confuso, y me obligo a entender cuando y donde se hace el destroy de cada clase, para ver en que momento intentaba destruir que, y seguir el flujo.

## EXCEPCIONES 

En el flujo de nuestro programa se lanzan varias excepciones, sin embargo, en los bloques importantes Cliente - Servidor solo hay 2 try-catch importantes, y los mismos se encuentran en el momento de enviar mensajes entre si, es decir, si falla la conexion, si no se puede bindear el server correctamente, lanza una excepcion que es catcheada - y se continua el flujo - lo ideal seria hacer en ese momento, utilizar un logger para que no se pierda la informacion del catch.

Entonces, si hay un problema al hacer _bind_ del servidor o al hacer _connect_ de parte del cliente, se catchea el Throw que lanza el Socket, y el flujo continua, en caso del cliente, finaliza. Luego, en el flujo de los mismos habra un try-catch el cual determina el fin de ejecucion ya que son resultado de: por ejemplo, cierre del socket servidor por ingreso de una "q" entonces el accept lanzara excepcion de que finalizo el servidor - y se continuara con el flujo de cierre de servidor. Este flujo esta detallado en 
**SECUENCIA SERVIDOR FIN**.
