/*
 * StrategySolicitud.cpp
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#include "common_StrategySolicitud.h"

StrategySolicitud::StrategySolicitud() {
	this->solicitud = NULL;
}

void StrategySolicitud::StrategyCrearSolicitud(std::string operacion) {
	if (!strcmp("define", operacion.c_str())) {
		this->solicitud = new SolicitudDefine();
	} else if (!strcmp("pop", operacion.c_str())) {
		this->solicitud = new SolicitudPop();
	} else if (!strcmp("push", operacion.c_str())) {
		this->solicitud = new SolicitudPush();
	} else {
		throw std::invalid_argument("Solicitud del cliente no existe.");
	}
}

std::string StrategySolicitud::StrategyRealizarSolicitud(MonitorColas &queue,
		Socket &socketCliente) {
	return this->solicitud->resolverSolicitud(queue, socketCliente);
}

void StrategySolicitud::StrategyEnviarInformacionSolicitada(
		Socket &socketCliente, std::string response) {
	this->solicitud->enviarInformacion(response, socketCliente);
}

void StrategySolicitud::StrategyEnviarInformacionSolicitadaPorCliente(
		Socket &socketCliente, std::string line) {
	this->solicitud->enviarInfomacionCliente(socketCliente, line);
}

void StrategySolicitud::StrategyRecibirInformacionDelServidor(
		Socket &socketServer) {
	this->solicitud->recibirInfomacionServidor(socketServer);
}

StrategySolicitud::~StrategySolicitud() {
	delete this->solicitud;
}

