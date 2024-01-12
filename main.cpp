#include "include/lib.h"
#include "include/struct.h"
#include <iostream>
using namespace std;

int main(int ac, char *av[])
{
    Dictionary dico;
    initialize_dictionary(dico);
    write(dico);
    char *word = "AA";

    if (dichotomy(dico, &word))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
