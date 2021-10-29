/*
 * Protocolo.h
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#ifndef COMMON_PROTOCOLO_H_
#define COMMON_PROTOCOLO_H_
#include <map>
#include <string>
#include "Socket.h"


class Protocolo {
	std::map<char,std::string> clienteServidor;
public:
	Protocolo();

	std::string recibir_solicitud_cliente(Socket& socketReceptor);

	std::string recibir_mensaje_cliente(Socket& socketReceptor);

	virtual ~Protocolo();
};

#endif /* COMMON_PROTOCOLO_H_ */
