/*
 * Protocolo.cpp
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#include "Protocolo.h"

Protocolo::Protocolo() {
	this->clienteServidor.insert({'d',"define"});
	this->clienteServidor.insert({'u',"push"});
	this->clienteServidor.insert({'o',"pop"});
}


std::string Protocolo::recibir_solicitud_cliente(Socket& socketReceptor){
	char operacionSolicitadaPorUsuario;
	size_t result = socketReceptor.receive(&operacionSolicitadaPorUsuario, 1);
	if(result == 0 || result == -1)
		throw std::invalid_argument("conexion cerrada");
	std::string operacion = this->clienteServidor.find(operacionSolicitadaPorUsuario)->second;
	return operacion;
}

std::string Protocolo::recibir_mensaje_cliente(Socket& socketReceptor){
	uint16_t cantidadMensaje;
	size_t result = socketReceptor.receive((char*)&cantidadMensaje,sizeof(uint16_t));
	int cantidadCaracteres = ntohs(cantidadMensaje);
	char* mensajeRecibido = (char*)malloc(cantidadCaracteres);
	result = socketReceptor.receive(mensajeRecibido,cantidadCaracteres);
	return mensajeRecibido;
}

Protocolo::~Protocolo() {

}

