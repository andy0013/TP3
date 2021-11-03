/*
 * Cliente.h
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#ifndef CLIENT_CLIENTE_H_
#define CLIENT_CLIENTE_H_
#include "../common/Socket.h"
#include "../common/Protocolo.h"
class Cliente {
	Socket sktCliente;
public:
	Cliente(char *argv[]);
	void comunicacion();
	virtual ~Cliente();
};

#endif /* CLIENT_CLIENTE_H_ */
