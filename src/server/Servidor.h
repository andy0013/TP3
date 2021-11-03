/*
 * Servidor.h
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#ifndef SERVER_SERVIDOR_H_
#define SERVER_SERVIDOR_H_
#include "../common/Protocolo.h"
#include "EscucharClientes.h"
#include "ColasProtegidas.h"

class Servidor {

	EscucharClientes escuchar;

public:
	Servidor(char *port);

	void comunicacion();

	virtual ~Servidor();
};

#endif /* SERVER_SERVIDOR_H_ */
