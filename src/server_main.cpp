/*
 * main.cpp
 *
 *  Created on: 23 oct. 2021
 *      Author: andres
 */

#include <iostream>

#include "server_Servidor.h"


int main(int argc, char *argv[]) {
	Servidor servidor(argv[1]);
	servidor.comunicacion();
	return 0;
}



