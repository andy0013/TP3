/*
 * Servidor.h
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#ifndef SERVER_SERVIDOR_H_
#define SERVER_SERVIDOR_H_
#include "../common/Protocolo.h"

class Servidor {
	Protocolo protocolo;
public:
	Servidor(char *port);

	void comunicacion();

	virtual ~Servidor();
};

#endif /* SERVER_SERVIDOR_H_ */
