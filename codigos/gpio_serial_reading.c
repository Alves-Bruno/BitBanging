/*
 * gpio_serial_reading.c
 *
 *  Created on: 23 de set de 2016
 *      Author: brunoalves
 */


/*
 * rfid.c
 *
 *  Created on: 9 de set de 2016
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

	int TX = 21, RX = 22;

	GPIO_pins(TX, RX);

	gpioSetPullUpDown(TX, PI_PUD_OFF);  // Clear any pull-ups/downs.
	gpioSetPullUpDown(RX, PI_PUD_OFF);  // Clear any pull-ups/downs.

	char *answer =  malloc(sizeof(char) * 2);
	char concatena[9];
	//	char *answer;
	gpioSerialReadOpen(RX, 19200, 32);
	// gpioSerialRead(RX, answer, 8);


	int cont;

	while (1){
		for (cont = 0; cont < 8; cont++) {

			gpioSerialRead(RX, answer, 1);
			//		printf("TAG: %s\n", answer);
			concatena[cont] = answer[0];
		}
		concatena[cont] = '\0';
		printf("TAG: %s\n", concatena);

	}

	gpioSerialReadClose(RX);

	return 0;
}

