/*
 * Protocolo.h
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#ifndef COMMON_COMMON_PROTOCOLO_H_
#define COMMON_COMMON_PROTOCOLO_H_
#include <map>
#include <string>

#include "common_Socket.h"


class Protocolo {
	std::map<char,std::string> clienteServidor;

	void obtenerCharParServidor(const std::string &operacion,
			char& claveParaServidor);

public:
	Protocolo();

	void enviarSolicitudClienteAlServidor(Socket& socketServer,const std::string& operacion);

	void enviarMensaje(Socket& socketServer,std::string& mensaje);

	std::string recibirSolicitudCliente(Socket& socketReceptor);

	std::string recibirMensaje(Socket& socketReceptor);

	virtual ~Protocolo();
};

#endif /* COMMON_COMMON_PROTOCOLO_H_ */
