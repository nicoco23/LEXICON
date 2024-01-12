using namespace std;

#include "../../include/lib.h"

void initialize_word(word_table &table)
{
    table.nb_word = 0;
}

void present_card(Deck &hand, Card &c)
{
    int cpt = 0;

    for (int i = 0; i < hand.current_nb_cards; i++)
    {
        Card &actual_card = hand.cards[i];

        if (actual_card.Name != c.Name)
            cpt++;
        else 
            break;
    }
}

void unstack_card(Deck &hand, Card &c)
{
    unsigned int cpt = 0;
    Deck deck_tmp;

    init_deck(deck_tmp, hand.nb_cards_max);
    for (int i = 0; i < hand.current_nb_cards; i++) {
        stack(deck_tmp, unstack(hand));
        cpt++;
        if (top(hand).Name == c.Name)
            break;
    }
    for (int i = 0; i < deck_tmp.current_nb_cards; i++)
        stack(hand, unstack(deck_tmp));
}

void unstack_word(Deck &hand, Word &w)
{
    for (int i = 0; i < w.lenght; i++) {
        Card &card_word = w.tab[i];
        unstack_card(hand, w.tab[i]);
    }
}

void add_word(word_table &table, Word &w)
{
    ++table.nb_word;
    table.game[table.nb_word] = w;
}