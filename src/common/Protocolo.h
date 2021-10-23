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
	std::map<std::string,std::string> clienteServidor;
	Socket cliente;
	Socket servidor;
public:
	Protocolo();

	void preparar_servidor(const char *port);

	void aceptar_cliente();

	void recibir_mensaje_cliente();

	virtual ~Protocolo();
};

#endif /* COMMON_PROTOCOLO_H_ */
