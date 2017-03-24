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

	gpioSetMode(RX, PI_INPUT);  // Set GPIO as input.

	gpioSetMode(TX, PI_OUTPUT); // Set GPIO as output.

}

int main (){

	inicia();

	int TX = 6, RX = 13;

	GPIO_pins(TX, RX);

	gpioSetPullUpDown(TX, PI_PUD_OFF);  // Clear any pull-ups/downs.
	gpioSetPullUpDown(RX, PI_PUD_OFF);  // Clear any pull-ups/downs.

    int read_open = gpioSerialReadOpen(RX, 9600, 32);
    if(read_open != 0){
        puts("SERIAL READ OPEN -->> ERROR!!!");
        finaliza();
        exit(1);
    }

	char *answer =  malloc(sizeof(char) * 200);

    int number_of_bytes = gpioSerialRead(RX, answer, 200);
    if(read_open == PI_BAD_USER_GPIO || read_open == PI_NOT_SERIAL_GPIO){
        puts("SERIAL READ -->> ERROR!!!");
        finaliza();
        exit(1);
    }

	gpioSerialReadClose(RX);

    printf("-->> Numero de bytes lido: %d\n", number_of_bytes);
    printf("-->> BUFFER lido:\n %s\n", answer);

	return 0;
}
