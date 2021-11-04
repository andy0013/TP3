/*
 * SolicitudPop.h
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#ifndef SERVER_SERVER_SOLICITUDPOP_H_
#define SERVER_SERVER_SOLICITUDPOP_H_
#include "common_ColasProtegidas.h"
#include "common_MonitorColas.h"
#include "common_Socket.h"
#include "common_Solicitud.h"
class SolicitudPop :public Solicitud{
public:
	SolicitudPop();

	std::string resolverSolicitud(MonitorColas& queue, Socket& socketCliente)override;

	void enviarInfomacionCliente(Socket& socketServer,std::string lineaInputCliente) override;

	void recibirInfomacionServidor(Socket& socketServer)override;

	void enviarInformacion(std::string response, Socket& socketCliente)override;

	virtual ~SolicitudPop();
};

#endif /* SERVER_SERVER_SOLICITUDPOP_H_ */
