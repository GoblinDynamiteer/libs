#include <stdio.h>
#include "../lib/libinput.h"

int main(){
	printf("You wrote: %g", inputDouble("Enter decimal number! : "));
	return 1;
}