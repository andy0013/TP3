/*
 * Solicitud.h
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#ifndef SERVER_SERVER_SOLICITUD_H_
#define SERVER_SERVER_SOLICITUD_H_
#include <string>

#include "common_ColasProtegidas.h"
#include "common_MonitorColas.h"
#include "common_Protocolo.h"
#include "common_Socket.h"
class Solicitud {
public:
	virtual std::string resolverSolicitud(MonitorColas& queue, Socket& socketCliente) = 0;

	virtual void enviarInformacion(std::string response, Socket& socketCliente) = 0;

	virtual void enviarInfomacionCliente(Socket& socketServer,std::string lineaInputCliente) = 0;

	virtual void recibirInfomacionServidor(Socket& socketServer) = 0;

	virtual ~Solicitud(){};
};

#endif /* SERVER_SERVER_SOLICITUD_H_ */
