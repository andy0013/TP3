/*
 * SolicitudPop.h
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#ifndef SERVER_SOLICITUDPOP_H_
#define SERVER_SOLICITUDPOP_H_
#include "Solicitud.h"
class SolicitudPop :public Solicitud{
public:
	SolicitudPop();

	std::string resolverSolicitud(ProtecetedQueue& queue, Socket& socketCliente)override;

	void enviarInformacion(std::string response, Socket& socketCliente)override;

	virtual ~SolicitudPop();
};

#endif /* SERVER_SOLICITUDPOP_H_ */
