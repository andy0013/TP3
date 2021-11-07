/*
 * Servidor.h
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#ifndef SERVER_SERVER_SERVIDOR_H_
#define SERVER_SERVER_SERVIDOR_H_
#include "common_ColasProtegidas.h"
#include "common_Protocolo.h"
#include "server_EscucharClientes.h"
#include <string>
#include <utility>

class Servidor {
	Socket servidor;

public:
	explicit Servidor(char *port);

	void comunicacion();

	virtual ~Servidor();
};

#endif /* SERVER_SERVER_SERVIDOR_H_ */
