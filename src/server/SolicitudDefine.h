/*
 * SolicitudDefine.h
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#ifndef SERVER_SOLICITUDDEFINE_H_
#define SERVER_SOLICITUDDEFINE_H_
#define VACIO ""
#include "Solicitud.h"
#include "ColasProtegidas.h"
#include "../common/Socket.h"
class SolicitudDefine :public Solicitud {
public:
	SolicitudDefine();
	std::string resolverSolicitud(MonitorColas& queue, Socket& socketCliente)override;
	void enviarInformacion(std::string response, Socket& socketCliente)override;
	virtual ~SolicitudDefine();
};

#endif /* SERVER_SOLICITUDDEFINE_H_ */
