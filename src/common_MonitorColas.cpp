/*
 * GestorColas.cpp
 *
 *  Created on: 29 oct. 2021
 *      Author: andres
 */

#include "common_MonitorColas.h"

MonitorColas::MonitorColas() {
	// TODO Auto-generated constructor stub
}

void MonitorColas::defineNuevaCola(std::string nombreCola){
	std::unique_lock<std::mutex> unique_lock(this->m);
	if(!(this->mapConColasProtegidas.find(nombreCola) != this->mapConColasProtegidas.end())){
		this->mapConColasProtegidas.insert({nombreCola, new ColasProtegidas()});
	}
}

std::string MonitorColas::popColaSiExiste(std::string nombreCola){
	this->m.lock();
	std::string popInfo;
	if(!(this->mapConColasProtegidas.find(nombreCola) != this->mapConColasProtegidas.end())){
		throw std::invalid_argument("cola_inexistente");
	}else{
		this->m.unlock();
		popInfo = this->mapConColasProtegidas.find(nombreCola)->second->obtenerInformacionSiEsPosible();
	}
	return popInfo;
}

void MonitorColas::pushColaSiExiste(std::string nombreCola,std::string mensaje){
	this->m.lock();
	if(!(this->mapConColasProtegidas.find(nombreCola) != this->mapConColasProtegidas.end())){
		throw std::invalid_argument("cola_inexistente");
	}else{
		this->m.unlock();
		this->mapConColasProtegidas.find(nombreCola)->second->agregarInformacionSiEsPosible(mensaje);
	}
}

MonitorColas::~MonitorColas() {
	std::map<std::string, ColasProtegidas*>:: iterator it = this->mapConColasProtegidas.begin();
	while (it != this->mapConColasProtegidas.end()) {
		delete it->second;
		it.operator ++();
	}
}

