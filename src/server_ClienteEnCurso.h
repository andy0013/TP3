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
#include "common_Protocolo.h"
#include "common_StrategySolicitud.h"
class ClienteEnCurso : public Thread{
private:
	Socket clienteSocket;
	bool clienteIntercambiaDatos;
	MonitorColas& monitor;
public:
	ClienteEnCurso(Socket cliente,MonitorColas& monitor);

	void run() override;

	bool clienteSigueEnCurso();

	ClienteEnCurso(ClienteEnCurso&& other);

	virtual ~ClienteEnCurso();
protected:
	void ejecutarRequest(std::string request);
};

#endif /* SRC_SERVER_CLIENTEENCURSO_H_ */
