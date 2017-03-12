/*   Bitwise operations
    By
    Johan Kämpe

    Assumes first bit from right is position 1
    0001 0001 0001 0011<- n=1

    2017-03-12
    First version
    */

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

/*   Output example
Decimal: 8
Binary: 0000 0000 0000 0000 0000 0000 0000 1100
Bit 03:                                     #   */
void printBinaryAndBitPosition(int num, int bit){
  printf("Decimal: %i \nBinary: ", num);
  printBinary(num);
  printf("\nBit %02i: ", bit);
  printPositionMarker(bit);
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

/*  Toggles (1 become 0 and vice versa) bit at position 'bit'   */
unsigned int toggleBitAtPosition(unsigned int num, int bit){
  /*   ^ = XOR = Exclusive OR
      Will toggle the bit.
      ORIGNAL BIT     XOR     RESULT
      0               1       1
      1               1       0
    */
  return num ^ (0x0001 << bit-1);
}

/*  Finds the highest set bit in a number   */
int findHighestSetBit(int num){
  /* First bit determines negative/positive number */
  for(int i = NUM_BITS - 1; i > 0; i--){
    if(checkBitAtPosition(num, i)){
      return i;
    }
  }
  return 0; //No bit set.
}
