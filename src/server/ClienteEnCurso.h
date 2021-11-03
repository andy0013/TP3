/*
 * ClienteEnCurso.h
 *
 *  Created on: 26 oct. 2021
 *      Author: andres
 */

#ifndef SRC_SERVER_CLIENTEENCURSO_H_
#define SRC_SERVER_CLIENTEENCURSO_H_
#include "../common/Socket.h"
#include "StrategySolicitud.h"
#include "../common/Protocolo.h"
#include "MonitorColas.h"
#include "ColasProtegidas.h"
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
