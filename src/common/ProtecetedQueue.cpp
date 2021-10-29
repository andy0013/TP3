/*
 * ProtecetedQueue.cpp
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#include "ProtecetedQueue.h"
#include <iostream>


ProtecetedQueue::ProtecetedQueue() {
	this->terminamos = false;
}


void ProtecetedQueue::agregarParticionSiEsPosible(std::string mensajeCliente) {
	std::unique_lock<std::mutex> unique_lock(this->m);
	 this->threads.push(mensajeCliente);
//	 this->taskVoid.notify_all();
}

void ProtecetedQueue::terminarQueue() {
	std::unique_lock<std::mutex> unique_lock(this->m);
//	this->terminamos = true;
//	this->taskVoid.notify_all();

		std::cout << this->threads.size() << std::endl;
}

std::string ProtecetedQueue::obtenerParticionSiEsPosible() {
	 std::unique_lock<std::mutex> unique_lock(this->m);
	 std::string mensajePopeado = this->threads.front();
	 this->threads.pop();
//	 this->taskFull.notify_all();
	 return mensajePopeado;
}


ProtecetedQueue::~ProtecetedQueue(){}
