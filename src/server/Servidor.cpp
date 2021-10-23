/*
 * Servidor.cpp
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#include "Servidor.h"

Servidor::Servidor(char *port) {
	this->protocolo.preparar_servidor(port);
}

void Servidor::comunicacion(){
	this->protocolo.aceptar_cliente();
//	this->protocolo.recibir_mensaje_cliente();
}


Servidor::~Servidor() {}

