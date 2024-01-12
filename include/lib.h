#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include "struct.h"

int my_atoi(char *str);

int nb_player(int ac, char *av[]);
void initialize_player(Player *player, int nb_player);
char *my_strcpy(char *dest, char *src);
int my_strcmp(char *s1, char *s2);
unsigned int count(const char *file);
void initialize_dictionary(Dictionary &dico);
void delete_dictionary(Dictionary &dico);
void write(Dictionary &dico);
bool dichotomy(Dictionary &dico, Item *elem);
unsigned int count(const char *file);

#endif  // FUNCTIONS_H