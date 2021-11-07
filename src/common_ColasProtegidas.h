/*
 * ProtecetedQueue.h
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#ifndef PROTECETEDQUEUE_H_
#define PROTECETEDQUEUE_H_

#include <queue>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>



class ColasProtegidas {
private:
	std::queue<std::string> informacionCola;
    std::mutex m;
    std::condition_variable colaVacia;

    ColasProtegidas(const ColasProtegidas &other) = delete;

    ColasProtegidas& operator=(const ColasProtegidas &other) = delete;

public:
	ColasProtegidas();

	void agregarInformacionSiEsPosible(std::string mensajeCliente);

	std::string obtenerInformacionSiEsPosible();

	virtual ~ColasProtegidas();
};

#endif /* PROTECETEDQUEUE_H_ */
