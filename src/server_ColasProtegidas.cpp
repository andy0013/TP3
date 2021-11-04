/*
 * ProtecetedQueue.cpp
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#include "server_ColasProtegidas.h"

#include <iostream>


ColasProtegidas::ColasProtegidas() {
}


void ColasProtegidas::agregarInformacionSiEsPosible(std::string mensajeCliente) {
	std::unique_lock<std::mutex> unique_lock(this->m);
	 this->informacionCola.push(mensajeCliente);
	 this->colaVacia.notify_all();
}

void ColasProtegidas::terminarQueue() {
	std::unique_lock<std::mutex> unique_lock(this->m);
	std::cout << this->informacionCola.size() << std::endl;
}

std::string ColasProtegidas::obtenerInformacionSiEsPosible() {
	 std::unique_lock<std::mutex> unique_lock(this->m);
	 while(this->informacionCola.empty()){
		 this->colaVacia.wait(unique_lock);
	 }
	 std::string mensajePopeado = this->informacionCola.front();
	 this->informacionCola.pop();
	 return mensajePopeado;
}



ColasProtegidas::~ColasProtegidas(){}
