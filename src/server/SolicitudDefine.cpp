/*
 * SolicitudDefine.cpp
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#include "SolicitudDefine.h"

SolicitudDefine::SolicitudDefine() {
}

std::string SolicitudDefine::resolverSolicitud(MonitorColas& queue, Socket& socketCliente){
	Protocolo comunicacion;
	std::string nombreCola = comunicacion.recibir_mensaje_cliente(socketCliente);
	queue.defineNuevaCola(nombreCola);
	return VACIO;
}

void SolicitudDefine::enviarInformacion(std::string response, Socket& socketCliente){}


SolicitudDefine::~SolicitudDefine() {
	// TODO Auto-generated destructor stub
}

