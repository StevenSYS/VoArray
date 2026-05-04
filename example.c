#define VOARRAY_DEFCONFIG
#include <stdio.h>

#include "voArray.h"

VOARRAY(int_vo, int);

int main() {
	VOARRAY_TYPE_SIZE i;
	int_vo intArray;
	
	intArray.size = 3;
	VOARRAY_INIT(int, intArray, 1);
	
	loop:
	for (i = 0; i < intArray.size; i++) {
		intArray.i[i] = (i + 1) * 5;
		printf("%i\n", intArray.i[i]);
	}
	
	if (intArray.size == 3) {
		intArray.size++;
		VOARRAY_RESIZE(int, intArray, 1);
		printf("- Resized\n");
		goto loop;
	}
	
	VOARRAY_UNINIT(intArray);
	return 0;
}