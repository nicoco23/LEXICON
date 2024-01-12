#include "include/lib.h"
#include "include/struct.h"
#include <iostream>
using namespace std;

int main(int ac, char *av[])
{
    int count_player = 0;
    count_player = atoi(av[1]);

    Player *player = new Player;
    initialize_player(player, count_player);

    return (0);
}
