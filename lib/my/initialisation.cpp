#include <cstdlib>
#include <ctime>
using namespace std;

#include "../../include/lib.h"

void init_table(Player_table &table, int nb_player)
{
    if (nb_player < 2 || nb_player > 4)
        cout << "Nombre de joueurs incorrect" << endl;
    else {
        table.nb_player = nb_player;
        table.registered = new Player[table.nb_player];

        for (int i = 0; i < table.nb_player; i++) {
            Player& actual_player = table.registered[i];
            actual_player.ID = i + 1;
            init_deck(actual_player.hand, NB_INIT_CARD);
            actual_player.score = 0;
            actual_player.nb_cards = 0;
            actual_player.is_playing = false;
        }

        cout << "Table de joueurs initialisée" << endl;
        cout << "Nombre de joueurs : " << table.nb_player << endl;
    }

}

void delete_table(Player_table &table)
{
    for (int i = 0; i < table.nb_player; i++) {
        Player &actual_player = table.registered[i];
        delete_deck(actual_player.hand);
    }
}


void mix(Deck &game)
{
    srand(time(NULL));
    for (int i = 0; i < game.current_nb_cards; i++) {
        int newCard = i + rand() % (NB_CARDS - i);
        Card tmp = game.cards[i];
        game.cards[i] = game.cards[newCard];
        game.cards[newCard] = tmp;
    }
}

void give_out(Deck &game, Player_table &table)
{
    for (int i = 0; i < table.nb_player; i++) {
        Player &actual_player = table.registered[i];
        while (actual_player.hand.current_nb_cards != (NB_INIT_CARD - 1)) {
            stack(actual_player.hand, unstack(game));
            actual_player.nb_cards++;
        }
    }
}

void select(Deck &defausse, Deck &pile)
{
    init_deck(pile, NB_CARDS);
    stack(pile, unstack(defausse));
}

void display(Deck &pile, Player_table &p_table, word_table &w_table)
{
    Player &player = p_table.registered[0];

    for (int i = 0; i < p_table.nb_player; i++) {
        player = p_table.registered[i];
        if (player.is_playing == true)
            break;
    }
    unsigned int pos = pile.current_nb_cards;
    cout << "* Joueur" << player.ID << "(" << pile.cards[pos].Name<< ")" <<endl;
    Deck &actual_hand = player.hand;
    for (int j = 0; j < actual_hand.current_nb_cards; j++) {
        Card &actual_card = actual_hand.cards[j];
        cout << actual_card.Name << " ";
    }
}

Player &activ_player(Player_table &table)
{
    for (int i = 0; i < table.nb_player; i++) {
        Player &actual_player = table.registered[i];
        if (actual_player.is_playing == true)
            return actual_player;
    }
}