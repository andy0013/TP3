/*
 * Servidor.h
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#ifndef SERVER_SERVER_SERVIDOR_H_
#define SERVER_SERVER_SERVIDOR_H_
#include "common_Protocolo.h"
#include "server_ColasProtegidas.h"
#include "server_EscucharClientes.h"

class Servidor {

	EscucharClientes escuchar;

public:
	Servidor(char *port);

	void comunicacion();

	virtual ~Servidor();
};

#endif /* SERVER_SERVER_SERVIDOR_H_ */