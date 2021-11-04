/*
 * StrategySolicitud.h
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#ifndef SERVER_SERVER_STRATEGYSOLICITUD_H_
#define SERVER_SERVER_STRATEGYSOLICITUD_H_
#include "common_Protocolo.h"
#include <string>
#include <cstring>

#include "common_Socket.h"
#include "common_Solicitud.h"
#include "common_SolicitudDefine.h"
#include "common_SolicitudPop.h"
#include "common_SolicitudPush.h"
#include "server_ColasProtegidas.h"
#include "server_MonitorColas.h"
class StrategySolicitud {
private:
	Solicitud *solicitud;

public:
	StrategySolicitud();

	void StrategyCrearSolicitud(std::string operacion);

	std::string StrategyRealizarSolicitud(MonitorColas& queue, Socket& socketCliente);

	void StrategyEnviarInformacionSolicitada(Socket& socketCliente,std::string response);

	void StrategyRecibirInformacionDelServidor(Socket& socketServer);

	void StrategyEnviarInformacionSolicitadaPorCliente(Socket& socketServer,std::string line);

	virtual ~StrategySolicitud();
};

#endif /* SERVER_SERVER_STRATEGYSOLICITUD_H_ */
