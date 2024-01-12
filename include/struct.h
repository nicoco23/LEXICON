#ifndef STRUCT_H
#define STRUCT_H

typedef struct Card
{
    int Value;
    char Name;
    int quantity;
}Card;

typedef struct Deck
{
    Card *cards;
    int nb_cards_max;
    int current_nb_cards;
}Deck;

typedef struct Player
{
    int ID;
    int score;
    bool is_playing;
    Deck *deck;
}Player;



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




















