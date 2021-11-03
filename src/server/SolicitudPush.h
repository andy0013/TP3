/*
 * SolicitudPush.h
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#ifndef SERVER_SOLICITUDPUSH_H_
#define SERVER_SOLICITUDPUSH_H_
#define VACIO ""
#include "ColasProtegidas.h"
#include "../common/Socket.h"
#include "Solicitud.h"
class SolicitudPush :public Solicitud {
public:
	SolicitudPush();

	std::string resolverSolicitud(MonitorColas& queue, Socket& socketCliente)override;

	void enviarInformacion(std::string response, Socket& socketCliente)override;

	virtual ~SolicitudPush();
};

#endif /* SERVER_SOLICITUDPUSH_H_ */
