/*
 * SolicitudDefine.h
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#ifndef SERVER_SERVER_SOLICITUDDEFINE_H_
#define SERVER_SERVER_SOLICITUDDEFINE_H_

#define VACIO ""
#include "common_Solicitud.h"
#include "server_ColasProtegidas.h"
#include "common_Socket.h"
class SolicitudDefine :public Solicitud {
public:
	SolicitudDefine();
	std::string resolverSolicitud(MonitorColas& queue, Socket& socketCliente)override;
	void enviarInfomacionCliente(Socket& socketServer,std::string lineaInputCliente) override;
	void recibirInfomacionServidor(Socket& socketServer)override;
	void enviarInformacion(std::string response, Socket& socketCliente)override;
	virtual ~SolicitudDefine();
};

#endif /* SERVER_SERVER_SOLICITUDDEFINE_H_ */
