/*
 * Cliente.cpp
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#include "../client/Cliente.h"
#include <algorithm>


Cliente::Cliente(char *argv[]) {
	sktCliente.connect(argv[1], argv[2]);
}

void Cliente::comunicacion(){
	int nroSolicitudUsuario = 0;
	std::string line;
	while (std::getline(std::cin, line)) {
		Protocolo protocolo;
		size_t ocurrenciasEspacio = std::count(line.begin(),line.end(),' ');
		std::string operacion = line.substr(0, line.find(" "));
		line = line.substr(line.find(" ")+1);
		std::string cola = line.substr(0, line.find(" "));
		line = line.substr(line.find(" ")+1);
		std::string mensaje = line.substr(0, line.find("\n"));
		protocolo.enviarSolicitudClienteAlServidor(operacion, cola, mensaje,ocurrenciasEspacio);


	}
}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

