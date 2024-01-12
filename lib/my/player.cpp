#include "../../include/lib.h"
#include "../../include/struct.h"
using namespace std;

void initialize_player(Player *player, int nb_player)
{
    int i = 0;
    int player_count = 1;
    while (i < nb_player) {
        player->ID = player_count;
        player->score = 0;
        player->is_playing = false;
        player->deck = NULL;
        player_count++;
        i++;
        cout << "Player " << player->ID << " created" << endl;
    }
}
