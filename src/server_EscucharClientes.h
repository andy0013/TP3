/*
 * escucharClientes.h
 *
 *  Created on: 24 oct. 2021
 *      Author: andres
 */

#ifndef SRC_SERVER_ESCUCHARCLIENTES_H_
#define SRC_SERVER_ESCUCHARCLIENTES_H_
#include <list>
#include <thread>

#include "common_Socket.h"
#include "server_ClienteEnCurso.h"
#include "server_ColasProtegidas.h"
#include "server_MonitorColas.h"

class EscucharClientes {
	Socket servidor;

	std::list<std::thread*> clientesEnCurso;
public:
	EscucharClientes() = default;

	EscucharClientes(Socket servidor);

	EscucharClientes(EscucharClientes &&other);

	EscucharClientes &operator=(EscucharClientes &&other);

	void operator()();

	virtual ~EscucharClientes();
};

#endif /* SRC_SERVER_ESCUCHARCLIENTES_H_ */
