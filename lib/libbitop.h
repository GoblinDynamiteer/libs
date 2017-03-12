/*   Bitwise operations

    Johan Kämpe */

#ifndef LIBBITOP_H
#define LIBBITOP_H

#include <stdio.h> //printf

/*  Bits in int (8 bits per byte)  */
#define NUM_BITS sizeof(int) * 8

/*  Functions in libbitop.c   */
int checkBitAtPosition(int num, int bit);
void printBinary(int hex);
void printPositionMarker(int num);
unsigned int setBitAtPosition(unsigned int num, int bit, int value);

#endif
