/*
 * Solicitud.h
 *
 *  Created on: 28 oct. 2021
 *      Author: andres
 */

#ifndef SERVER_SOLICITUD_H_
#define SERVER_SOLICITUD_H_
#include <string>
#include "../common/Protocolo.h"
#include "../common/Socket.h"
#include "MonitorColas.h"
#include "ColasProtegidas.h"
class Solicitud {
public:
	virtual std::string resolverSolicitud(MonitorColas& queue, Socket& socketCliente) = 0;

	virtual void enviarInformacion(std::string response, Socket& socketCliente) = 0;

	virtual ~Solicitud(){};
};

#endif /* SERVER_SOLICITUD_H_ */
