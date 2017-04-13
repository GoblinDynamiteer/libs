/*   Atmega328p functions */

#ifndef _LIBAVR_H
#define _LIBAVR_H

#include <avr/io.h>

typedef unsigned char uint8_t;

enum{INPUT, OUTPUT};
enum{OFF, ON};

void pinMode(uint8_t pin, uint8_t io);
uint8_t getPortPin(uint8_t pin);
uint8_t getPort(uint8_t pin);
void setPin(uint8_t pin, uint8_t onOff);

#define sleep(x) _delay_ms(x)
#define wait(x) _delay_ms(x)

#endif
