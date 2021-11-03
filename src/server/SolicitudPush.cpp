/*
 * SolicitudPush.cpp
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#include "SolicitudPush.h"

SolicitudPush::SolicitudPush() {


}

std::string SolicitudPush::resolverSolicitud(MonitorColas& queue, Socket& socketCliente){
	Protocolo comunicacion;
	std::string nombreCola = comunicacion.recibir_mensaje_cliente(socketCliente);
	std::string mensajePorPushear = comunicacion.recibir_mensaje_cliente(socketCliente);
	queue.pushColaSiExiste(nombreCola, mensajePorPushear);
	return VACIO;
}

void SolicitudPush::enviarInformacion(std::string response, Socket& socketCliente){}

SolicitudPush::~SolicitudPush() {
	// TODO Auto-generated destructor stub
}

