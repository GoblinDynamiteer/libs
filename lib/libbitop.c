/*   Bitwise operations

    Assues first bit from right is position 1

    Johan Kämpe */

#include "libbitop.h"

/*   Returns bit value at position 'bit'  */
int checkBitAtPosition(int num, int bit){
  int a = 0x0001 << bit-1; //Assumes the first bit starts at 1
  return ((num & a) > 0);
}

/*   For binary output  */
void printBinary(int num){
  int spacer = 3;
  for(int i = NUM_BITS; i > 0; i--){
    printf("%i", checkBitAtPosition(num, i));
    if(!spacer--){
      printf(" ");
      spacer = 3;
    }
  }
}

/*  Prints "#" at bit position, to be used with printBinary()  */
void printPositionMarker(int num){
  int spacer = 3;
  for(int i = 1; i < NUM_BITS; i++){
    printf(" ");
    if(!spacer--){
      printf(" ");
      spacer = 3;
    }
    if(i == NUM_BITS - num){
      break;
    }
  }
  printf("#");
}

/*  Set bit at specific position to 1/0 */
unsigned int setBitAtPosition(unsigned int num, int bit, int value){
  if(value){ //set bit to 1
    /*   Shift in 1 to correct bit position to set to 1
        and OR with num, the bit at postion 'bit' will be 1 */
    num = num | (0x0001 << bit-1);
  }
  else{ //set bit to 0
    /*   Shift in 1 to correct bit position to set to 0,
        inverse all digits, and AND with num, the bit at
        position 'bit' will be 0 */
    num = num & ~(0x0001 << bit-1);
  }
  /*   Returns new number  */
  return num;
}

unsigned int toggleBitAtPosition(unsigned int num, int bit){
  /*   ^ = XOR = Exclusive OR
      Will toggle the bit.
      ORIGNAL BIT     XOR     RESULT
      0               1       1
      1               1       0
    */
  return num ^ (0x0001 << bit-1);
}
