#ifndef __DBG_H__
#define __DBG_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
extern int errno;

#ifdef DEBUG
#define PRN_ERRMSG() \
	({ \
		fprintf(stderr, "[ERROR]%s[%d]:%s:%s\n\r", \
			__FILE__, __LINE__, __FUNCTION__, strerror(errno)); \
		exit(-1); \
	})
#else
#define PRN_ERRMSG() exit(-1)
#endif

#endif
