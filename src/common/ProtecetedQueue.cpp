/*
 * ProtecetedQueue.cpp
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#include "ProtecetedQueue.h"
#include <iostream>


ColasProtegidas::ColasProtegidas() {
	this->terminamos = false;
}


void ColasProtegidas::agregarInformacionSiEsPosible(std::string mensajeCliente) {
	std::unique_lock<std::mutex> unique_lock(this->m);
	 this->informacionCola.push(mensajeCliente);
//	 this->taskVoid.notify_all();
}

void ColasProtegidas::terminarQueue() {
	std::unique_lock<std::mutex> unique_lock(this->m);
//	this->terminamos = true;
//	this->taskVoid.notify_all();

		std::cout << this->informacionCola.size() << std::endl;
}

std::string ColasProtegidas::obtenerInformacionSiEsPosible() {
	 std::unique_lock<std::mutex> unique_lock(this->m);
	 std::string mensajePopeado = this->informacionCola.front();
	 this->informacionCola.pop();
//	 this->taskFull.notify_all();
	 return mensajePopeado;
}


ColasProtegidas::~ColasProtegidas(){}
