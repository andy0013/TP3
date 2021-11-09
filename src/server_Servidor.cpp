/*
 * Servidor.cpp
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#include "server_Servidor.h"

Servidor::Servidor(char *port): escucharClientes(this->servidor) {
	servidor.bind_and_listen(NULL, port);
	this->escucharClientes.start();
}


void Servidor::comunicacion(){
	std::string line;
	while(std::getline(std::cin,line)){
		if(line == "q"){
			this->servidor.close();
			break;
		}
	}
}




Servidor::~Servidor() {}

