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
#include <utility>
#define FLAG_CLIENTE 0
#define FLAG_SERVIDOR AI_PASSIVE

#ifndef SOCKET_H_
#define SOCKET_H_

class Socket {
private:
	int fd;

	Socket(const Socket &other) = delete;

	Socket& operator=(const Socket &other) = delete;

public:
	Socket() = default;

	explicit Socket(int fd);

	Socket(Socket&& other);

	Socket &operator=(Socket &&other);

	void bind_and_listen(const char *host, const char *service);

	Socket accept();

	void connect(const char *host, const char *service);

	bool send(const char *buffer, size_t length);

	bool receive(char* buffer, size_t length);

	void close();

	virtual ~Socket();
};

#endif /* SOCKET_H_ */
