#ifndef FT_BOOLEAN_H
#   define FT_BOOLEAN_H

#include <unistd.h>

typedef enum bool
{
	TRUE, FALSE
} t_bool;
#define EVEN(nb) (nb % 2 == 0) ? 1 : 0
#define EVEN_MSG "I have an even number of arguments\n"
#define ODD_MSG "I have an odd number of arguments\n"
#define SUCCESS 0

#endif