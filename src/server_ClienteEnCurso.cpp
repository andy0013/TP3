/*
 * ClienteEnCurso.cpp
 *
 *  Created on: 26 oct. 2021
 *      Author: andres
 */

#include "server_ClienteEnCurso.h"

ClienteEnCurso::ClienteEnCurso(Socket cliente,MonitorColas& monitor):
	clienteIntercambiaDatos(true),monitor(monitor){
	this->clienteSocket = std::move(cliente);
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

void ClienteEnCurso::parar(){
	this->clienteIntercambiaDatos = false;
	this->clienteSocket.close();
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

