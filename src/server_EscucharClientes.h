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
//#include <invoke.h>
#include <utility>
#include "common_ColasProtegidas.h"
#include "common_MonitorColas.h"
#include "common_Socket.h"
#include "server_Thread.h"
#include "server_ClienteEnCurso.h"

class EscucharClientes : public Thread{
private:
	std::list<ClienteEnCurso*> clientesEnCurso;
	Socket& servidor;
	MonitorColas monitorColas;

	void eliminarThreadQueFinalizoComunicacion();

public:
	explicit EscucharClientes(Socket& servidor);

	void run() override;

	~EscucharClientes() override;
	void finalizarHilosClientes();
};

#endif /* SRC_SERVER_ESCUCHARCLIENTES_H_ */
