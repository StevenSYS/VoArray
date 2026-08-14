#ifndef __VOARRAY__
#define __VOARRAY__

#ifdef VOARRAY_DEFCONFIG
	#include "voArray_defConfig.h"
#else
	#include "voArray_config.h"
#endif

/* Macros */

/* These two can be used to make a private VoArray type. */
#define VOARRAY_ST(_name, _type) \
	struct _name { \
		_type *i; \
		VOARRAY_TYPE_SIZE size; \
	}

#define VOARRAY_SNAME(_name, _sName, _type) typedef VOARRAY_ST(_sName, _type) _name

/* This is the one you will probably want to use. */
#define VOARRAY(_name, _type) VOARRAY_SNAME(_name, , _type)

#define VOARRAY_UNINIT(_var) \
	if (_var.i != NULL) { \
		VOARRAY_FREE(_var.i); \
		_var.i = NULL; \
	} \
	_var.size = 0;

/* Raw Size */
#define VOARRAY_INIT_RAWSIZE(_type, _var, _errRet, _size) \
	_var.i = (_type *)VOARRAY_MALLOC(_size); \
	if (_var.i == NULL) { \
		return _errRet; \
	}

#define VOARRAY_RESIZE_RAWSIZE(_type, _var, _errRet, _size) \
	_var.i = (_type *)VOARRAY_REALLOC((void *)_var.i, _size); \
	if (_var.i == NULL) { \
		return _errRet; \
	}

/* Variable Size */
#define VOARRAY_INIT(_type, _var, _errRet) \
	if (_var.size) { \
		VOARRAY_INIT_RAWSIZE( \
			_type, \
			_var, \
			_errRet, \
			sizeof(_type[_var.size]) \
		); \
	}

#define VOARRAY_RESIZE(_type, _var, _errRet) \
	if (_var.size) { \
		VOARRAY_RESIZE_RAWSIZE( \
			_type, \
			_var, \
			_errRet, \
			sizeof(_type[_var.size]) \
		); \
	}

#endif