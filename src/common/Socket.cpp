/*
 * Socket.cpp
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#include "Socket.h"

Socket::Socket() {
	this->fd = -2;
}

Socket::Socket(int fd) {
	this->fd = fd;
}


static struct addrinfo* addrinfo_server_o_cliente(const char *host,
		const char *port, int hints_flags) {
	struct addrinfo *addr_obtenido;
	struct addrinfo hints;
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = hints_flags;
	if ((getaddrinfo(host, port, &hints, &addr_obtenido)) != 0) {
		return NULL;
	}
	return addr_obtenido;
}

Socket::Socket(Socket&& other){
	this->fd = other.fd;
	other.fd = -1;
}


int Socket::bind_and_listen(const char *host,const char *service) {
	int conectado = 0;
	int conexion_exitosa = -1;
	struct addrinfo *addr_result, *i;
	addr_result = addrinfo_server_o_cliente(NULL, service, FLAG_SERVIDOR);
	int fd_obtenido = -1;
	for (i = addr_result; i != NULL && conectado == 0; i = i->ai_next) {
		fd_obtenido = socket(i->ai_family, i->ai_socktype, i->ai_protocol);
		conexion_exitosa = bind(fd_obtenido, i->ai_addr, i->ai_addrlen);
		if (conexion_exitosa == 0) {
			conectado = 1;
		}
	}
	this->fd = fd_obtenido;
	freeaddrinfo(addr_result);
	if (conectado) {
		int listening = 0;
		listening = listen(this->fd, 10);
		if (listening == -1) {
			return 1;
		}
	}

	return conexion_exitosa;
}

Socket Socket::accept() {
	int fd_client = ::accept(this->fd, NULL, NULL);
	return std::move(Socket(fd_client));
}

int Socket::connect(const char *host, const char *service) {
	int conectado = 0;
	int conexion_exitosa = -1;
	struct addrinfo *addr_obtenido, *i;
	addr_obtenido = addrinfo_server_o_cliente(host, service,
			FLAG_CLIENTE);
	int fd = -1;
	for (i = addr_obtenido; i != NULL && conectado == 0; i = i->ai_next) {
		fd = socket(i->ai_family, i->ai_socktype, i->ai_protocol);
		conexion_exitosa = ::connect(fd, i->ai_addr, i->ai_addrlen);
		if (conexion_exitosa == 0) {
			conectado = 1;
		}
	}
	this->fd = fd;
	freeaddrinfo(addr_obtenido);
	return conexion_exitosa;
}

size_t Socket::send(const char *buffer, size_t bytes_a_enviar) {
	int bytes_enviados = 0;
	int socket_conectado = 1;
	while ((bytes_enviados < bytes_a_enviar) && (socket_conectado) ) {
		ssize_t bytes = 0;
		bytes = ::send(this->fd, &buffer[bytes_enviados],
				bytes_a_enviar - bytes_enviados,MSG_NOSIGNAL);
		if ((bytes == -1) || (bytes == 0)) {
			socket_conectado = 0;
		}
		bytes_enviados += bytes;
	}
	return bytes_enviados;
}

size_t Socket::receive(char *buffer, size_t length) {
	int bytes_recibidos = 0;
	int socket_conectado = 1;
	while ((bytes_recibidos < length) && (socket_conectado)) {
		ssize_t bytes = 0;
		bytes = ::recv(this->fd, &buffer[bytes_recibidos],
				length - bytes_recibidos, 0);
		if ((bytes == -1) || (bytes == 0)) {
			socket_conectado = 0;
			break;
		}
		bytes_recibidos += bytes;
	}
	return bytes_recibidos;
}

Socket::~Socket() {
	if (this->fd)
		shutdown(this->fd, SHUT_RDWR);
		close(this->fd);
}

