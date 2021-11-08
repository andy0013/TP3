/*
 * Servidor.cpp
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#include "server_Servidor.h"

Servidor::Servidor(char *port) {
	servidor.bind_and_listen(NULL, port);
}


void Servidor::comunicacion(){
	std::string line;
	EscucharClientes hiloEscuchaClientes(this->servidor);
	hiloEscuchaClientes.start();
	while(std::getline(std::cin,line)){
		if(line == "q"){
			this->servidor.close();
			break;
		}
	}
}




Servidor::~Servidor() {}

