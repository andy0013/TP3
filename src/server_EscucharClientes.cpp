/*
 * escucharClientes.cpp
 *
 *  Created on: 24 oct. 2021
 *      Author: andres
 */

#include "server_EscucharClientes.h"

EscucharClientes::EscucharClientes(Socket& servidor):
	servidor(servidor){}

void EscucharClientes::finalizarHilosClientes() {
	 std::list<ClienteEnCurso *>::iterator it = this->clientesEnCurso.begin();
	 while (it != this->clientesEnCurso.end()) {
		(*it)->parar();
		delete *it;
		it.operator ++();
	}
}

void EscucharClientes::run(){
	bool enCurso = true;
	while (enCurso) {
		Socket cliente;
		try {
			cliente = this->servidor.accept();
		}
		catch (std::invalid_argument &e) {
			enCurso = false;
			break;
		}
		ClienteEnCurso* clienteConectado = new ClienteEnCurso(std::move(cliente),monitorColas);
		this->clientesEnCurso.push_back(clienteConectado);
		clienteConectado->start();
		eliminarThreadQueFinalizoComunicacion();
	}
}

void EscucharClientes::eliminarThreadQueFinalizoComunicacion() {
    std::list<ClienteEnCurso *>::iterator it = this->clientesEnCurso.begin();
    while (it != this->clientesEnCurso.end()) {
        if (!(*it)->clienteSigueEnCurso()) {
            delete *it;
            it = this->clientesEnCurso.erase(it);
        } else {
            it.operator ++();
        }
    }
}

EscucharClientes::~EscucharClientes() {
	finalizarHilosClientes();
	this->join();
}

