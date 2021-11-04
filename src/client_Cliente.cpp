/*
 * Cliente.cpp
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#include "client_Cliente.h"

#include <algorithm>


Cliente::Cliente(char *argv[]) {
	sktCliente.connect(argv[1], argv[2]);
}

void Cliente::comunicacion(){
	std::string line;
	while (std::getline(std::cin, line)) {
		StrategySolicitud solicitudCliente;
		std::string operacion = line.substr(0, line.find(" "));
		solicitudCliente.StrategyCrearSolicitud(operacion);
		solicitudCliente.StrategyEnviarInformacionSolicitadaPorCliente(sktCliente, line);
		solicitudCliente.StrategyRecibirInformacionDelServidor(sktCliente);
	}
}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

