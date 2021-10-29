/*
 * SolicitudPush.h
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#ifndef SERVER_SOLICITUDPUSH_H_
#define SERVER_SOLICITUDPUSH_H_
#define VACIO ""
#include "Solicitud.h"
class SolicitudPush :public Solicitud {
public:
	SolicitudPush();

	std::string resolverSolicitud(ProtecetedQueue& queue, Socket& socketCliente)override;

	void enviarInformacion(std::string response, Socket& socketCliente)override;

	virtual ~SolicitudPush();
};

#endif /* SERVER_SOLICITUDPUSH_H_ */
