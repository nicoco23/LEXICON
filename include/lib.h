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
bool dichotomy(Dictionary &dico, Item elem);
unsigned int count(const char *file);
void init_deck(Deck &d, unsigned int c);
void delete_deck(Deck &d);
bool isEmpty(Deck &d);
Card top(Deck &d);
bool is_full(const Deck &d);
void stack(Deck &d, const Card &c);
Card unstack(Deck &d);
void init_table(Player_table &table, int nb_player);
void delete_table(Player_table &table);
void mix(Deck &game);
void give_out(Deck &game, Player_table &table);
void select(Deck &defausse, Deck &pile);
void display(Deck &pile, Player_table &p_table, word_table &w_table);
Player &activ_player(Player_table &table);
void initialize_word(word_table &table);


#endif  // FUNCTIONS_H