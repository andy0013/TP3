/*
 * SolicitudDefine.cpp
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#include "common_SolicitudDefine.h"

SolicitudDefine::SolicitudDefine() {
}

std::string SolicitudDefine::resolverSolicitud(MonitorColas& queue, Socket& socketCliente){
	Protocolo comunicacion;
	std::string nombreCola = comunicacion.recibirMensaje(socketCliente);
	queue.defineNuevaCola(nombreCola);
	return VACIO;
}

void SolicitudDefine::enviarInfomacionCliente(Socket& socketServer,std::string lineaInputCliente){
	Protocolo comunicacion;
	std::string operacion = lineaInputCliente.substr(0, lineaInputCliente.find(" "));
	lineaInputCliente = lineaInputCliente.substr(lineaInputCliente.find(" ")+1);
	std::string nombreCola = lineaInputCliente.substr(0, lineaInputCliente.find("\n"));
	comunicacion.enviarSolicitudClienteAlServidor(socketServer, operacion);
	comunicacion.enviarMensaje(socketServer, nombreCola);
}

void SolicitudDefine::recibirInfomacionServidor(Socket& socketServer){}


void SolicitudDefine::enviarInformacion(std::string response, Socket& socketCliente){}


SolicitudDefine::~SolicitudDefine() {
	// TODO Auto-generated destructor stub
}

