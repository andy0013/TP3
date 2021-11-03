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

std::string SolicitudPop::resolverSolicitud(MonitorColas& queue, Socket& socketCliente){
	Protocolo comunicacion;
	std::string nombreCola = comunicacion.recibir_mensaje_cliente(socketCliente);
	return queue.popColaSiExiste(nombreCola);
}

void SolicitudPop::enviarInformacion(std::string response, Socket& socketCliente){
	socketCliente.send(response.c_str(), (int)response.length());
}


SolicitudPop::~SolicitudPop() {
	// TODO Auto-generated destructor stub
}

