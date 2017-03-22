/*
 * full_comunication.c
 *
 *  Created on: 14 de out de 2016
 *      Author: brunoalves
 */

// COMPILAR: gcc -Wall -pthread -o exec_full full_comunication.c -lpigpio -lrt -lpigpiod_if2
//-Wall -pthread -lpigpio -lrt -lpigpiod_if2

#include <string.h> /* memset */
#include <pigpio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pigpiod_if2.h>

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
	int pi_start;
	pi_start = pigpio_start(NULL, NULL);


	int handle, cont;
	char *buf = (char *) malloc(2 * sizeof(char));
	handle = serial_open(pi_start, "/dev/ttyS0", 19200, 0);

	for (cont = 0; cont < 10; cont++){

		serial_write_byte(pi_start, handle, 0xFF);
		serial_write_byte(pi_start, handle, 0x00);
		serial_write_byte(pi_start, handle, 0x01);
		serial_write_byte(pi_start, handle, 0x83);
		serial_write_byte(pi_start, handle, 0x84);

		sleep(1);

		while (serial_data_available(pi_start, handle) > 0){

			serial_read(pi_start, handle, buf, 1);
			printf ("%x", buf[0]);
			memset(buf, 0, 2);
		}
		printf("\n");
	}

	serial_close(pi_start, handle);
	pigpio_stop(pi_start);


	return 0;
}

