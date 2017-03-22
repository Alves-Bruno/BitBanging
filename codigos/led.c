/*
 * cu.c
 *
 *  Created on: 11 de set de 2016
 *      Author: brunoalves
 */

#include <pigpio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void inicia (void){

	if (gpioInitialise() < 0) {
		printf ("GPIO ERROR -- inicializacao\n\n");
	}

}

void finaliza (void){

	gpioTerminate();

}

void GPIO_pins (int TX, int RX){

	gpioSetMode(RX, PI_INPUT);  // Set GPIO17 as input.

	gpioSetMode(TX, PI_OUTPUT); // Set GPIO18 as output.


}


int main (){

	inicia();

	int TX = 20, RX = 17;

	GPIO_pins(TX, RX);


	gpioWrite(TX, 1);
	sleep(1);
	gpioWrite(TX, 0);
	sleep(1);


}
