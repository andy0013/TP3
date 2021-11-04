/*
 * SolicitudPop.cpp
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#include "common_SolicitudPop.h"

SolicitudPop::SolicitudPop() {
	// TODO Auto-generated constructor stub

}

std::string SolicitudPop::resolverSolicitud(MonitorColas& queue, Socket& socketCliente){
	Protocolo comunicacion;
	std::string nombreCola = comunicacion.recibirMensaje(socketCliente);
	return queue.popColaSiExiste(nombreCola);
}

void SolicitudPop::enviarInformacion(std::string response, Socket& socketCliente){
	Protocolo comunicacion;
	comunicacion.enviarResponseACliente(socketCliente, response);
}

void SolicitudPop::enviarInfomacionCliente(Socket& socketServer,std::string lineaInputCliente){
	Protocolo comunicacion;
	std::string operacion = lineaInputCliente.substr(0, lineaInputCliente.find(" "));
	lineaInputCliente = lineaInputCliente.substr(lineaInputCliente.find(" ")+1);
	std::string nombreCola = lineaInputCliente.substr(0, lineaInputCliente.find(" "));
	lineaInputCliente = lineaInputCliente.substr(lineaInputCliente.find(" ")+1);
	std::string mensajePorPushear = lineaInputCliente.substr(0, lineaInputCliente.find("\n"));
	comunicacion.enviarSolicitudClienteAlServidor(socketServer, operacion);
	comunicacion.enviarMensaje(socketServer, nombreCola);
	comunicacion.enviarMensaje(socketServer, mensajePorPushear);
}

void SolicitudPop::recibirInfomacionServidor(Socket& socketServer){
	Protocolo comunicacion;
	std::cout << comunicacion.recibirMensaje(socketServer) << std::endl;
}


SolicitudPop::~SolicitudPop() {
	// TODO Auto-generated destructor stub
}

