/*
 * Protocolo.cpp
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#include "common_Protocolo.h"

Protocolo::Protocolo() {
	this->clienteServidor.insert({'d',"define"});
	this->clienteServidor.insert({'u',"push"});
	this->clienteServidor.insert({'o',"pop"});
}

void Protocolo::obtenerCharParServidor(const std::string &operacion,
		char& claveParaServidor) {
	for (auto it = this->clienteServidor.begin();
			it != this->clienteServidor.end(); it++) {
		if (it->second == operacion) {
			claveParaServidor = it->first;
		}
	}
}

void Protocolo::enviarSolicitudClienteAlServidor(Socket& socketServer,std::string operacion){
	char claveParaServidor;
	obtenerCharParServidor(operacion, claveParaServidor);
	socketServer.send(&claveParaServidor, sizeof(char));
}

void Protocolo::enviarMensaje(Socket& socketServer,std::string& mensaje){
	uint16_t lenMensaje = mensaje.size();
	uint16_t mensajeConLenMensaje = htons(lenMensaje);
	socketServer.send((char*)&mensajeConLenMensaje, sizeof(uint16_t));
	socketServer.send(mensaje.c_str(), lenMensaje);
}

std::string Protocolo::recibirSolicitudCliente(Socket& socketReceptor){
	char operacionSolicitadaPorUsuario;
	bool result = socketReceptor.receive(&operacionSolicitadaPorUsuario, 1);
	if(!result)
		throw std::invalid_argument("conexion cerrada");
	std::string operacion = this->clienteServidor.find(operacionSolicitadaPorUsuario)->second;
	return operacion;
}

std::string Protocolo::recibirMensaje(Socket& socketReceptor){
	uint16_t cantidadMensaje;
	socketReceptor.receive((char*)&cantidadMensaje,sizeof(uint16_t));
	int cantidadCaracteres = ntohs(cantidadMensaje);
	char* mensajeRecibido = (char*)calloc(1,cantidadCaracteres);
	socketReceptor.receive(mensajeRecibido,cantidadCaracteres);
	return mensajeRecibido;
}


Protocolo::~Protocolo() {

}

