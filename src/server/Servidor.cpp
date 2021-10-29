/*
 * Servidor.cpp
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#include "Servidor.h"

Servidor::Servidor(char *port) {
	Socket servidor;
	servidor.bind_and_listen(NULL, port);
	this->escuchar = std::move(EscucharClientes(std::move(servidor)));
}

void Servidor::comunicacion(){
	std::string line;
	std::thread t1(std::ref(this->escuchar));
	while(std::getline(std::cin,line)){
		if(line == "q")
			break;
	}


}


Servidor::~Servidor() {}

