#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include "struct.h"

int my_atoi(char *str);

int nb_player(int ac, char *av[]);
void initialize_player(Player *player, int nb_player);

#endif  // FUNCTIONS_H