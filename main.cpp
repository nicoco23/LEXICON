#include "include/lib.h"
#include "include/struct.h"
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
}
