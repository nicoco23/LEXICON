#ifndef STRUCT_H
#define STRUCT_H

enum { NB_CARDS = 51, NB_LETTERS = 26, NB_INIT_CARD = 10 };
enum { NB_MAX_SCORE = 100, NB_MIN_PLAYER = 2, NB_MAX_PLAYER = 4 };
enum { NB_CHAR_MAX = 16};

typedef char *Item;

typedef struct Card
{
    int Value;
    char Name;
    int quantity;
}Card;

typedef struct Deck
{
    Card *cards;
    unsigned int nb_cards_max;
    unsigned int current_nb_cards;
}Deck;

typedef struct Word
{
    Card *tab;
    unsigned int lenght;
}Word;

typedef struct Player
{
    unsigned int ID;
    unsigned int score;
    unsigned int nb_cards;
    bool is_playing;
    Deck *hand;
}Player;

typedef struct Dictionary
{
    unsigned int lenght;
    Item *words;
}Dictionary;

typedef struct  Maillon
{
    char valeur;
    Maillon *suivant;
} Maillon;

typedef struct Chaine
{
    Maillon *premier;
    Maillon **now;
} Chaines;


#endif /*STRUCT_H*/




















