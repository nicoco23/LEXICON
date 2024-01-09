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
