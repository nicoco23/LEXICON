#include "../../include/lib.h"

int my_atoi(char *str)
{
    int i = 0;
    unsigned int nbr = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        nbr = nbr * 10;
        nbr = nbr + (str[i] - '0');
    }
    return (nbr);   
}

