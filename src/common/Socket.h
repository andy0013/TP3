/*
 * Socket.h
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <stdexcept>
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>

#define FLAG_CLIENTE 0
#define FLAG_SERVIDOR AI_PASSIVE

#ifndef SOCKET_H_
#define SOCKET_H_

class Socket {

public:
	Socket() = default;

	explicit Socket(int fd);

	Socket(Socket&& other);

	Socket &operator=(Socket &&other);

	int bind_and_listen( const char *host, const char *service);

	Socket accept();

	int connect(const char *host, const char *service);

	size_t send(const char *buffer, size_t length);

	size_t receive(char *buffer, size_t length);

	void close();

	virtual ~Socket();
private:
	int fd;




};

#endif /* SOCKET_H_ */
