/*
 * StrategySolicitud.cpp
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#include "StrategySolicitud.h"

StrategySolicitud::StrategySolicitud() {
	this->solicitud = NULL;
}

void StrategySolicitud::StrategyCrearSolicitud(std::string operacion){
	if (!strcmp("define", operacion.c_str())) {
		this->solicitud = new SolicitudDefine();
	}
	if (!strcmp("pop", operacion.c_str())) {
		this->solicitud = new SolicitudPop();
	}
	if (!strcmp("push", operacion.c_str())) {
		this->solicitud = new SolicitudPush();
	}
}

std::string StrategySolicitud::StrategyRealizarSolicitud(MonitorColas& queue, Socket& socketCliente){
	return this->solicitud->resolverSolicitud(queue, socketCliente);
}

void StrategySolicitud::StrategyEnviarInformacionSolicitada(Socket& socketCliente,std::string response){
	this->solicitud->enviarInformacion(response, socketCliente);
}


StrategySolicitud::~StrategySolicitud() {
	// TODO Auto-generated destructor stub
}

