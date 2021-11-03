/*
 * escucharClientes.cpp
 *
 *  Created on: 24 oct. 2021
 *      Author: andres
 */

#include "EscucharClientes.h"

EscucharClientes::EscucharClientes(Socket servidor) {
	this->servidor = std::move(servidor);
}

EscucharClientes::EscucharClientes(EscucharClientes &&other){
	this->clientesEnCurso = std::move(other.clientesEnCurso);
	this->servidor = std::move(other.servidor);

}

EscucharClientes &EscucharClientes::operator=(EscucharClientes &&other){
    this->clientesEnCurso = std::move(other.clientesEnCurso);
    this->servidor = std::move(other.servidor);
    return *this;
}

void EscucharClientes::operator()(){
	bool enCurso = true;
	MonitorColas monitorColas;
	while (enCurso) {
		Socket cliente;
		try {
		cliente = this->servidor.accept();
		}
		catch (std::invalid_argument) {
			break;
		}
		ClienteEnCurso clienteConectado(std::move(cliente),monitorColas);
		this->clientesEnCurso.push_back(new std::thread(std::move(clienteConectado)));

	}
}

EscucharClientes::~EscucharClientes() {
	// TODO Auto-generated destructor stub
}

