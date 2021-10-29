/*
 * SolicitudPush.cpp
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#include "SolicitudPush.h"

SolicitudPush::SolicitudPush() {


}

std::string SolicitudPush::resolverSolicitud(ProtecetedQueue& queue, Socket& socketCliente){
	Protocolo comunicacion;
	std::string mensaje = comunicacion.recibir_mensaje_cliente(socketCliente);
	queue.agregarParticionSiEsPosible(mensaje);
	return VACIO;
}

void SolicitudPush::enviarInformacion(std::string response, Socket& socketCliente){}

SolicitudPush::~SolicitudPush() {
	// TODO Auto-generated destructor stub
}

