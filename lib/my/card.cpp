using namespace std;
#include <cassert>

#include "../../include/lib.h"

void init_deck(Deck &d, unsigned int c)
{
    assert(c > 0);
    d.nb_cards_max = c;
    d.cards = new Card[c];
    d.current_nb_cards =-1;
}

void delete_deck(Deck &d)
{
    delete[] d.cards;
    d.cards = NULL;
}

bool isEmpty(Deck &d)
{
    return d.current_nb_cards == -1;
}

Card top(Deck &d)
{
    assert(!isEmpty(d));
    return d.cards[d.current_nb_cards];
}

bool is_full(const Deck &d)
{
    return (d.current_nb_cards == (d.nb_cards_max - 1));
}

void stack(Deck &d, const Card &c)
{
    assert(!is_full(d));
    d.current_nb_cards++;
    d.cards[d.current_nb_cards] = c;
}

Card unstack(Deck &d)
{
    assert(!isEmpty(d));
    Card c = d.cards[d.current_nb_cards];
    d.current_nb_cards--;
    return c;
}