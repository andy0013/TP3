/*
 * StrategySolicitud.h
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#ifndef SERVER_STRATEGYSOLICITUD_H_
#define SERVER_STRATEGYSOLICITUD_H_
#include "Solicitud.h"
#include "SolicitudDefine.h"
#include "SolicitudPush.h"
#include "SolicitudPop.h"
#include "ColasProtegidas.h"
#include "MonitorColas.h"
#include "../common/Protocolo.h"
#include "../common/Socket.h"
#include <string>
#include <cstring>
class StrategySolicitud {
private:
	Solicitud *solicitud;

public:
	StrategySolicitud();

	void StrategyCrearSolicitud(std::string operacion);

	std::string StrategyRealizarSolicitud(MonitorColas& queue, Socket& socketCliente);

	void StrategyEnviarInformacionSolicitada(Socket& socketCliente,std::string response);

	virtual ~StrategySolicitud();
};

#endif /* SERVER_STRATEGYSOLICITUD_H_ */
