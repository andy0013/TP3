/*
 * ProtecetedQueue.h
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#ifndef PROTECETEDQUEUE_H_
#define PROTECETEDQUEUE_H_

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>



class ProtecetedQueue {
private:
	std::queue<std::string> threads;
    std::mutex m;
    bool terminamos;

    ProtecetedQueue(const ProtecetedQueue &other) = delete;

    ProtecetedQueue& operator=(const ProtecetedQueue &other) = delete;

public:
	explicit ProtecetedQueue();

	void terminarQueue();

	void agregarParticionSiEsPosible(std::string mensajeCliente);

	std::string obtenerParticionSiEsPosible();

	virtual ~ProtecetedQueue();
};

#endif /* PROTECETEDQUEUE_H_ */
