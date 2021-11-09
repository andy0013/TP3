/*
 * Cliente.cpp
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#include "client_Cliente.h"

#include <algorithm>


Cliente::Cliente(char *argv[]) {
	try{
		sktCliente.connect(argv[1], argv[2]);
	}catch(std::invalid_argument& e){
		this->sktCliente.close();
	}
}

void Cliente::comunicacion(){
	std::string line;
	while (std::getline(std::cin, line)) {
		if (!strcmp("exit", line.c_str())) break;
		StrategySolicitud solicitudCliente;
		std::string operacion = line.substr(0, line.find(" "));
		try{
			solicitudCliente.StrategyCrearSolicitud(operacion);
			solicitudCliente.StrategyEnviarInformacionSolicitadaPorCliente(sktCliente, line);
			solicitudCliente.StrategyRecibirInformacionDelServidor(sktCliente);
		}catch(std::invalid_argument& e){
			break;
		}
	}
}

Cliente::~Cliente() {
	this->sktCliente.close();
}

