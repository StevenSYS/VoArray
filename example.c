#define VOARRAY_DEFCONFIG
#include <stdio.h>

#include "voArray.h"

VOARRAY(intDA_t, int);

int main() {
	VOARRAY_TYPE_SIZE i;
	intDA_t intArray;
	
	intArray.size = 3;
	VOARRAY_INIT(int, intArray, 1);
	
	for (i = 0; i < intArray.size; i++) {
		intArray.i[i] = (i + 1) * 5;
		printf("%i\n", intArray.i[i]);
	}
	
	VOARRAY_UNINIT(intArray);
	return 0;
}