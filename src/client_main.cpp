/*
 * clientCliente.cpp
 *
 *  Created on: 2 nov. 2021
 *      Author: andres
 */


#include <iostream>

#include "client_Cliente.h"


int main(int argc, char *argv[]) {
	try{
		Cliente cliente(argv);
		cliente.comunicacion();
	}catch(std::invalid_argument& e){
		return 1;
	}
	return 0;
}



