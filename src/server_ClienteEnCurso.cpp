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


void ClienteEnCurso::run(){
	Protocolo comunicacion;
    while (this->clienteIntercambiaDatos) {
    	std::string buffer;
    	try{
    		buffer = comunicacion.recibirSolicitudCliente(clienteSocket);
    		ejecutarRequest(buffer);
    	} catch(std::invalid_argument& e){
    		this->clienteIntercambiaDatos = false;
    	}
    }
}

bool ClienteEnCurso::clienteSigueEnCurso(){
	return this->clienteIntercambiaDatos;
}

void ClienteEnCurso::clienteYaSigueEnCurso(){
	this->clienteSocket.close();
	this->clienteIntercambiaDatos = false;
}


void ClienteEnCurso::ejecutarRequest(std::string buffer){
	StrategySolicitud ejecutor;
	ejecutor.StrategyCrearSolicitud(buffer);
	std::string response = ejecutor.StrategyRealizarSolicitud(monitor, clienteSocket);
	ejecutor.StrategyEnviarInformacionSolicitada(clienteSocket, response);
}

ClienteEnCurso::~ClienteEnCurso() {
	this->clienteSocket.close();
    this->join();
}

