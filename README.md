# BITBANGING 

**Como transformar qualquer GPIO em RX, TX**

----------------------

### Biblioteca utilizada

[PIGPIO](http://abyz.co.uk/rpi/pigpio/). Biblioteca com suporte a C e Phyton.

> Creio que utilizar python é uma maneira mais fácil para realizar o Bitbanging (Criação de waves, envio e recebimento de dados).

----------------------

### Exemplos Simples


| Descrição | Arquivo |
| --------- |:-------:|
|Ligar um led com a biblioteca PIGPIO. |[File](codigos/led.c)|
|Ler e escrever dados nas portas RX, TX padrão. |[File](codigos/full_comunication.c)|

-----------------------

### Bitbanging exemplos 

| Descrição | Arquivo |
| --------- |:-------:|
|Ler dados padrão serial no pino RX = 22.|[File](codigos/gpio_serial_reading.c)|
|Escrever dados padrão serial em um gpio qualquer.|[Link](http://raspberrypi.stackexchange.com/questions/24806/9-data-bits-on-uart-pins)|

------------------------

### Hardware

Conectar Raspberry Py and Arduino ([Link](https://oscarliang.com/raspberry-pi-and-arduino-connected-serial-gpio/)).
Disposição dos GPIOs do Raspberry Py ([Link](http://abyz.co.uk/rpi/pigpio/index.html)).

