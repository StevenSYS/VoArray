#ifndef __VOARRAY__
#define __VOARRAY__

#ifdef VOARRAY_DEFCONFIG
	#include "voArray_defConfig.h"
#else
	#include "voArray_config.h"
#endif

/* Macros */
#define VOARRAY(_name, _type) \
	typedef struct { \
		_type *i; \
		VOARRAY_TYPE_SIZE length; \
	} _name;

#define VOARRAY_INIT(_type, _var, _errRet) \
	if (_var.length) { \
		_var.i = (_type *)VOARRAY_MALLOC( \
			sizeof(_type[_var.length]) \
		); \
		if (_var.i == NULL) { \
			return _errRet; \
		} \
	}

#define VOARRAY_RESIZE(_type, _var, _errRet) \
	if (_var.length) { \
		_var.i = (_type *)VOARRAY_REALLOC( \
			(void *)_var.i, \
			sizeof(_type[_var.length]) \
		); \
		if (_var.i == NULL) { \
			return _errRet; \
		} \
	} \

#define VOARRAY_UNINIT(_var) \
	if (_var.i != NULL) { \
		VOARRAY_FREE(_var.i); \
		_var.i = NULL; \
	} \
	_var.length = 0;

#endif