/*
 * Cliente.h
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#ifndef CLIENT_CLIENT_CLIENTE_H_
#define CLIENT_CLIENT_CLIENTE_H_
#include "common_StrategySolicitud.h"
#include "common_Socket.h"
#include <string>
#include <cstring>
class Cliente {
	Socket sktCliente;

	Cliente(const Cliente &other) = delete;

	Cliente& operator=(const Cliente &other) = delete;

public:
	explicit Cliente(char *argv[]);
	void comunicacion();
	virtual ~Cliente();
};

#endif /* CLIENT_CLIENT_CLIENTE_H_ */
