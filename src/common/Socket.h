/*
 * Socket.h
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */
#include <iostream>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>


#define FLAG_CLIENTE 0
#define FLAG_SERVIDOR AI_PASSIVE

#ifndef SOCKET_H_
#define SOCKET_H_

class Socket {
	int fd;
public:
	Socket();

	Socket(Socket&& other);

	int bind_and_listen( const char *host, const char *service);

	Socket accept();

	int connect(const char *host, const char *service);

	size_t send(const char *buffer, size_t length);

	size_t receive(char *buffer, size_t length);

	virtual ~Socket();
private:
	Socket(int fd);

};

#endif /* SOCKET_H_ */
