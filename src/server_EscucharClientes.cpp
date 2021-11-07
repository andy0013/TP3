/*
 * escucharClientes.cpp
 *
 *  Created on: 24 oct. 2021
 *      Author: andres
 */

#include "server_EscucharClientes.h"

EscucharClientes::EscucharClientes(Socket& servidor):
	servidor(servidor){
}

void EscucharClientes::esperarQueFinaliceComunicacionConClientesActuales() {
	while (!this->clientesEnCurso.empty()) {
		eliminarThreadQueFinalizoComunicacion();
	}
}

void EscucharClientes::run(){
	bool enCurso = true;
	MonitorColas monitorColas;
	while (enCurso) {
		Socket cliente;
		try {
			cliente = this->servidor.accept();
			ClienteEnCurso* clienteConectado = new ClienteEnCurso(std::move(cliente),monitorColas);
			this->clientesEnCurso.push_back(clienteConectado);
			clienteConectado->start();
			eliminarThreadQueFinalizoComunicacion();
		}
		catch (std::invalid_argument &e) {
			break;
		}
	}
	esperarQueFinaliceComunicacionConClientesActuales();
}

void EscucharClientes::eliminarThreadQueFinalizoComunicacion() {
    std::list<ClienteEnCurso *>::iterator it = this->clientesEnCurso.begin();
    while (it != this->clientesEnCurso.end()) {
        if (!(*it)->clienteSigueEnCurso()) {
            delete *it;
            it = this->clientesEnCurso.erase(it);
        } else {
            it++;
        }
    }
}

EscucharClientes::~EscucharClientes() {
	// TODO Auto-generated destructor stub
}

