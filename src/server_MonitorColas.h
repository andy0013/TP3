/*
 * GestorColas.h
 *
 *  Created on: 29 oct. 2021
 *      Author: andres
 */

#ifndef SERVER_SERVER_MONITORCOLAS_H_
#define SERVER_SERVER_MONITORCOLAS_H_
#include <map>
#include <queue>
#include <mutex>
#include <string>

#include "server_ColasProtegidas.h"
class MonitorColas {
private:
	std::map<std::string, ColasProtegidas*> mapConColasProtegidas;
    std::mutex m;

    MonitorColas(const MonitorColas &other) = delete;

    MonitorColas& operator=(const MonitorColas &other) = delete;

public:
	explicit MonitorColas();

	void defineNuevaCola(std::string nombreCola);

	std::string popColaSiExiste(std::string nombreCola);

	void pushColaSiExiste(std::string nombreCola, std::string mensaje);

	virtual ~MonitorColas();
};

#endif /* SERVER_SERVER_MONITORCOLAS_H_ */
