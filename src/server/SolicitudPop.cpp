/*
 * SolicitudPop.cpp
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#include "SolicitudPop.h"

SolicitudPop::SolicitudPop() {
	// TODO Auto-generated constructor stub

}

std::string SolicitudPop::resolverSolicitud(ProtecetedQueue& queue, Socket& socketCliente){
	//FALTA LOGICA DE VARIAS QUEUE
	return queue.obtenerParticionSiEsPosible();
}

void SolicitudPop::enviarInformacion(std::string response, Socket& socketCliente){
	socketCliente.send(response.c_str(), (int)response.length());
}


SolicitudPop::~SolicitudPop() {
	// TODO Auto-generated destructor stub
}

