/*
 * SolicitudPush.cpp
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#include "common_SolicitudPush.h"

SolicitudPush::SolicitudPush() {}

std::string SolicitudPush::resolverSolicitud(MonitorColas& queue, Socket& socketCliente){
	Protocolo comunicacion;
	std::string nombreCola = comunicacion.recibirMensaje(socketCliente);
	std::string mensajePorPushear = comunicacion.recibirMensaje(socketCliente);
	queue.pushColaSiExiste(nombreCola, mensajePorPushear);
	return VACIO;
}

void SolicitudPush::enviarInfomacionCliente(Socket& socketServer,std::string lineaInputCliente){
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

void SolicitudPush::recibirInfomacionServidor(Socket& socketServer){}


void SolicitudPush::enviarInformacion(std::string& response, Socket& socketCliente){}

SolicitudPush::~SolicitudPush() {
	// TODO Auto-generated destructor stub
}

