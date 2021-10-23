/*
 * Protocolo.cpp
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#include "Protocolo.h"

Protocolo::Protocolo() {
	this->clienteServidor.insert(std::pair<std::string,std::string>("define","d"));
	this->clienteServidor.insert(std::pair<std::string,std::string>("push","u"));
	this->clienteServidor.insert(std::pair<std::string,std::string>("pop","o"));
}

void Protocolo::preparar_servidor(const char* port){
	this->servidor.bind_and_listen(NULL, port);
}

void Protocolo::aceptar_cliente(){
	Socket s = this->servidor.accept();
	char buffer[1];
	s.receive(buffer, 1);
//	this->servidor.receive(buffer, 1);
	std::cout << buffer << std::endl;
}

void Protocolo::recibir_mensaje_cliente(){
}


Protocolo::~Protocolo() {

}

