/*   Bitwise operations library

    Assumes first bit from right is position 1
    0001 0001 0001 0011<- n=1

    by Johan Kämpe
    https://www.linkedin.com/in/johankampe/
    https://github.com/GoblinDynamiteer/

*/

#ifndef LIBBITOP_H
#define LIBBITOP_H

#include <stdio.h> //printf

/*  Bits in int (8 bits per byte)  */
#define NUM_BITS sizeof(int) * 8

/*  Functions in libbitop.c   */

/*	 Bit operations on numbers	*/
int checkBitAtPosition(int num, int bit);
unsigned int setBitAtPosition(unsigned int num, int bit, int value);
unsigned int toggleBitAtPosition(unsigned int num, int bit);
int findHighestSetBit(int num);
int findLowestSetBit(int num);

/*	 Text output */
void printBinaryAndBitPosition(int num, int bit);
void printBinary(int hex);
void printPositionMarker(int num);

#endif
