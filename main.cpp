#include "include/lib.h"
#include <iostream>
using namespace std;

int main(int ac, char *av[])
{
    Dictionary dico;
    initialize_dictionary(dico);
    write(dico);
    char word[NB_CHAR_MAX];

    my_strcpy(word, "ARBRE");
    if (dichotomy(dico, word))
        cout << "le mot est present" << endl;
    else
        cout << "le mot n'est pas present" << endl;

    Card game[NB_LETTERS] = {
        {'A', 10, 2},
		{'B', 2, 2},
		{'C', 8, 2},
		{'D', 6, 2},
		{'E', 10, 5},
		{'F', 2, 1},
		{'G', 4, 2},
		{'H', 8, 2},
		{'I', 10, 4},
		{'J', 6, 1},
		{'K', 8, 1},
		{'L', 8, 2},
		{'M', 8, 1},
		{'N', 8, 3},
		{'O', 8, 2},
		{'P', 8, 1},
		{'Q', 4, 1},
		{'R', 8, 3},
		{'S', 8, 3},
		{'T', 8, 3},
		{'U', 8, 3},
		{'V', 8, 1},
		{'W', 8, 1},
		{'X', 2, 1},
		{'Y', 4, 1},
		{'Z', 2, 1}
    };

    //debug jeu de cartes
    for (int i = 0; i < NB_LETTERS; i++) {
        cout << "Lettre : " << game[i].Name << " " << game[i].Value << " " << game[i].quantity << endl;
    }
    Player_table table;
    if (ac != 2) {
        cout << "Nombre de joueurs incorrect" << endl;
        return 84;
    }
    int nb_player = atoi(av[1]);
    if (nb_player < 2 || nb_player > 4) {
        cout << "Nombre de joueurs incorrect" << endl;
        return 84;
    }

    init_table(table, nb_player);

    cout << "Deck init" << endl;
    Deck game_deck;
    cout << "Deck created" << endl;
    init_deck(game_deck, NB_CARDS);
    cout << "Deck init sucess" << endl;
    for (int i = 0; i < NB_LETTERS; i++) {
        for (int j = 0; j < game[i].quantity; j++)
            stack(game_deck, game[i]);
    }
    cout << "Deck" << endl;
    int nb_cards = 0;
    for (int i = 0; i < game_deck.current_nb_cards; ++i) {
        Card &actual_card = game_deck.cards[i];
        cout << " carte actuelle : "<< actual_card.Name;
        ++nb_cards;
    }
    cout << endl;
    if (nb_cards != NB_CARDS)
        cout << "Erreur dans le nombre de cartes" << endl;
    else
        cout << "Nombre de cartes correct" << endl;
    mix(game_deck);
    for (int i = 0; i < game_deck.current_nb_cards; i++) {
        Card &actual_card = game_deck.cards[i];
        cout << actual_card.Name;
    }
    cout << endl;

    give_out(game_deck, table);
    //debug de la distribution du deck
    for (int i = 0; i < nb_player; i++) {
        Player& actual_player = table.registered[i];
        Deck& actual_hand = actual_player.hand;
        cout << "Joueur " << actual_player.ID << endl;
        for (int j = 0; j < NB_INIT_CARD; j++) {
            Card &actual_card = actual_hand.cards[j];
            cout << actual_card.Name;
        }
        cout << endl;
    }
    cout << "Talon" << endl;
    for (int i = 0; i < game_deck.current_nb_cards; i++) {
        Card &actual_card = game_deck.cards[i];
        cout << actual_card.Name;
    }
    cout << endl;

    // initialisation de la pile exposée

    Deck exposed_card; 
    select(game_deck, exposed_card);
    cout << "Talon" << endl;
    for (int i = 0; i < exposed_card.current_nb_cards; i++) {
        Card &actual_card = exposed_card.cards[i];
        cout << actual_card.Name;
    }
    cout << endl;
    cout << "Nouveau Talon" << endl;
    for (int i = 0; i < exposed_card.current_nb_cards; i++) {
        Card &actual_card = exposed_card.cards[i];
        cout << actual_card.Name;
    }
    cout << endl;
    cout << "Pile exposée" << endl;
    for (int i = 0; i < exposed_card.current_nb_cards; i++) {
        Card &actual_card = exposed_card.cards[i];
        cout << actual_card.Name;
    }
    cout << endl;

    // initialisation de la table de mots
    word_table w_table;
    initialize_word(w_table);

    // initialisation du joueur actif
    table.registered[0].is_playing = true;
    display(exposed_card, table, w_table);

    //destruction

    delete_deck(game_deck);
    delete_table(table);
    delete_dictionary(dico);
    return 0;
}

