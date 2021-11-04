/*
 * clientCliente.cpp
 *
 *  Created on: 2 nov. 2021
 *      Author: andres
 */


#include <iostream>

#include "client_Cliente.h"


int main(int argc, char *argv[]) {
	Cliente cliente(argv);
	cliente.comunicacion();
	return 0;
}



