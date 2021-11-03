/*
 * GestorColas.cpp
 *
 *  Created on: 29 oct. 2021
 *      Author: andres
 */

#include "MonitorColas.h"

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
	std::unique_lock<std::mutex> unique_lock(this->m);
	std::string popInfo;
	if(!(this->mapConColasProtegidas.find(nombreCola) != this->mapConColasProtegidas.end())){
		throw std::invalid_argument("cola_inexistente");
	}else{
		popInfo = this->mapConColasProtegidas.find(nombreCola)->second->obtenerInformacionSiEsPosible();
	}
	return popInfo;
}

void MonitorColas::pushColaSiExiste(std::string nombreCola,std::string mensaje){
	std::unique_lock<std::mutex> unique_lock(this->m);
	if(!(this->mapConColasProtegidas.find(nombreCola) != this->mapConColasProtegidas.end())){
		throw std::invalid_argument("cola_inexistente");
	}else{
		this->mapConColasProtegidas.find(nombreCola)->second->agregarInformacionSiEsPosible(mensaje);
	}
}

MonitorColas::~MonitorColas() {
}

