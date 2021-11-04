/*
 * ClienteEnCurso.cpp
 *
 *  Created on: 26 oct. 2021
 *      Author: andres
 */

#include "server_ClienteEnCurso.h"

ClienteEnCurso::ClienteEnCurso(Socket cliente,MonitorColas& monitor):
	monitor(monitor){
	this->clienteSocket = std::move(cliente);
	this->clienteIntercambiaDatos = true;
}

ClienteEnCurso::ClienteEnCurso(ClienteEnCurso&& other):
	monitor((other.monitor)){
	this->clienteSocket = std::move(other.clienteSocket);
	this->clienteIntercambiaDatos = other.clienteIntercambiaDatos;
}


void ClienteEnCurso::operator()(){
	Protocolo comunicacion;
    while (this->clienteIntercambiaDatos) {
    	std::string buffer;
    	try{
    		buffer = comunicacion.recibirSolicitudCliente(clienteSocket);
    	}catch (std::invalid_argument& e){
    		this->clienteIntercambiaDatos = false;
    	}
    	ejecutarRequest(buffer);
    }
}

bool ClienteEnCurso::informacionInvalida(std::string buffer){
	return false;
}

void ClienteEnCurso::ejecutarRequest(std::string buffer){
	StrategySolicitud ejecutor;
	ejecutor.StrategyCrearSolicitud(buffer);
	std::string response = ejecutor.StrategyRealizarSolicitud(monitor, clienteSocket);
	ejecutor.StrategyEnviarInformacionSolicitada(clienteSocket, response);
}

void ClienteEnCurso::enviarInformacionSolicitada(std::string response){

}


ClienteEnCurso::~ClienteEnCurso() {
	this->clienteSocket.close();
}
