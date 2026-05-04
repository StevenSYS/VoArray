/*
	If you're using VoArray in a project and
	you need to change one or more of these macros,
	copy this file to your project's include directory,
	modify the macros, and rename the new file to "voArray_config.h".
	
	You can also remove this comment if you want.
	
	If you want to use this file define a macro called "VOARRAY_DEFCONFIG".
*/
#include <stdlib.h>

/* Macros */
#define VOARRAY_MALLOC malloc
#define VOARRAY_REALLOC realloc
#define VOARRAY_FREE free
#define VOARRAY_TYPE_SIZE size_t