/*
 * SolicitudPush.h
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#ifndef SERVER_SERVER_SOLICITUDPUSH_H_
#define SERVER_SERVER_SOLICITUDPUSH_H_

#define VACIO ""
#include "server_ColasProtegidas.h"
#include "common_Socket.h"
#include "common_Solicitud.h"
class SolicitudPush :public Solicitud {
public:
	SolicitudPush();

	std::string resolverSolicitud(MonitorColas& queue, Socket& socketCliente)override;

	void enviarInfomacionCliente(Socket& socketServer,std::string lineaInputCliente) override;

	void recibirInfomacionServidor(Socket& socketServer)override;

	void enviarInformacion(std::string response, Socket& socketCliente)override;

	virtual ~SolicitudPush();
};

#endif /* SERVER_SERVER_SOLICITUDPUSH_H_ */
