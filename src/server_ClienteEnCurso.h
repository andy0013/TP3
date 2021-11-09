/*
 * ClienteEnCurso.h
 *
 *  Created on: 26 oct. 2021
 *      Author: andres
 */

#ifndef SRC_SERVER_CLIENTEENCURSO_H_
#define SRC_SERVER_CLIENTEENCURSO_H_
#include "common_ColasProtegidas.h"
#include "common_MonitorColas.h"
#include "common_Socket.h"
#include "server_Thread.h"
#include <string>
#include <utility>
#include <atomic>
#include "common_Protocolo.h"
#include "common_StrategySolicitud.h"
class ClienteEnCurso : public Thread{
private:
	Socket clienteSocket;
	std::atomic<bool> clienteIntercambiaDatos;
	MonitorColas& monitor;
public:
	ClienteEnCurso(Socket cliente,MonitorColas& monitor);

	void run() override;

	bool clienteSigueEnCurso();

	void parar();

	~ClienteEnCurso() override;
protected:
	void ejecutarRequest(std::string request);
};

#endif /* SRC_SERVER_CLIENTEENCURSO_H_ */
