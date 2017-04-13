/*   Atmega328p functions */

#include "libavr.h"

void pinMode(uint8_t pin, uint8_t io){
	switch(getPort(pin)){
		/* Port C */
		case 'C':
			if(io){	DDRC |= (1 << getPortPin(pin));	}
			else{		DDRC &= ~(1 << getPortPin(pin));	}
			break;
		/* Port D */
		case 'D':
			if(io){	DDRD |= (1 << getPortPin(pin));	}
			else{		DDRD &= ~(1 << getPortPin(pin));	}
			break;
		/* Port B */
		case 'B':
			if(io){	DDRB |= (1 << getPortPin(pin));	}
			else{		DDRB &= ~(1 << getPortPin(pin));	}
			break;
	}
}

void setPin(uint8_t pin, uint8_t onOff){
	switch(getPort(pin)){
		/* Port C */
		case 'C':
			if(onOff){	PORTC |= (1 << getPortPin(pin));	}
			else{				PORTC &= ~(1 << getPortPin(pin));	}
			break;
		/* Port D */
		case 'D':
			if(onOff){	PORTD |= (1 << getPortPin(pin));	}
			else{				PORTD &= ~(1 << getPortPin(pin));	}
			break;
		/* Port B */
		case 'B':
			if(onOff){	PORTB |= (1 << getPortPin(pin));	}
			else{				PORTB &= ~(1 << getPortPin(pin));	}
			break;
	}
}

uint8_t getPortPin(uint8_t pin){
	const uint8_t num[28] = {
		6,0,1,2,3,4,0,0,6,7,5,6,7,0,1,2,3,4,5,0,0,0,0,1,2,3,4,5
	};
	return num[pin-1];
}

uint8_t getPort(uint8_t pin){
	switch (pin) {
		case 1:		case 23:	case 24:	case 25:
		case 26:	case 27:	case 28:
			return 'C';
		case 2:		case 3:		case 4:		case 5:
		case 6:		case 11:	case 12:	case 13:
			return 'D';
		case 9:		case 10:	case 14:	case 15:
		case 16:	case 17:	case 18:	case 19:
			return 'B';
		}
	return '!'; //Wrong pin
}
