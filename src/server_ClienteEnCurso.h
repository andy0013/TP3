/*
 * ClienteEnCurso.h
 *
 *  Created on: 26 oct. 2021
 *      Author: andres
 */

#ifndef SRC_SERVER_CLIENTEENCURSO_H_
#define SRC_SERVER_CLIENTEENCURSO_H_
#include "common_Socket.h"
#include "common_Protocolo.h"
#include "common_StrategySolicitud.h"
#include "server_ColasProtegidas.h"
#include "server_MonitorColas.h"
class ClienteEnCurso {
private:
	Socket clienteSocket;
	bool clienteIntercambiaDatos;
	MonitorColas& monitor;
public:
	ClienteEnCurso(Socket cliente,MonitorColas& monitor);

	void operator()();

	ClienteEnCurso(ClienteEnCurso&& other);

	virtual ~ClienteEnCurso();
protected:

	void ejecutarRequest(std::string);

	bool informacionInvalida(std::string);

	void enviarInformacionSolicitada(std::string response);

};

#endif /* SRC_SERVER_CLIENTEENCURSO_H_ */
