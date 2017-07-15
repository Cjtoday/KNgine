#ifndef __K_LOGGER_HP__
#define __K_LOGGER_HP__
#include "K_Config.hpp"

#include <cstdio>

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#if K_DEBUG == 1
#define K_PRINTLN_DEBUG(fmt, ...)\
do{printf("%s:%d >> " fmt "\n", __FILENAME__ ,__LINE__, __VA_ARGS__);}while(0)
#define K_PRINT_DEBUG(fmt, ...)\
do{printf("%s:%d >> " fmt, __FILENAME__ ,__LINE__, __VA_ARGS__);}while(0)
#define K_REPRINT_DEBUG(fmt, ...)\
do{printf("\r%s:%d >> " fmt, __FILENAME__ ,__LINE__, __VA_ARGS__);}while(0)
#else
#define K_PRINTLN_DEBUG
#define K_PRINT_DEBUG 
#define K_REPRINT_DEBUG
#endif

#endif // __K_LOGGER_HP__
