/*
 * SolicitudDefine.cpp
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#include "SolicitudDefine.h"

SolicitudDefine::SolicitudDefine() {
	// TODO Auto-generated constructor stub

}

std::string SolicitudDefine::resolverSolicitud(ProtecetedQueue& queue, Socket& socketCliente){
	Protocolo comunicacion;
	std::string mensaje = comunicacion.recibir_mensaje_cliente(socketCliente);
//  pensar mas adelante, necesito una lisa de pilas, no es una sola PILA IMPORTANTE;
	return VACIO;
}

void SolicitudDefine::enviarInformacion(std::string response, Socket& socketCliente){}


SolicitudDefine::~SolicitudDefine() {
	// TODO Auto-generated destructor stub
}

