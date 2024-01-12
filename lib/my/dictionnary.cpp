#pragma warning(disable: 4996)
using namespace std;

#include "../../include/lib.h"

#include <fstream>
#include <iomanip> // Include the <iomanip> header for setw

unsigned int count(const char *file)
{
    ifstream in(file);
    if (!in)
    {
        cerr << "Impossible d'ouvrir le fichier " << file << endl;
        exit(EXIT_FAILURE);
    }
    unsigned int size = 0;
    char word[NB_CHAR_MAX];

    while (in >> setw(NB_CHAR_MAX) >> word)
        size++;
    in.close();
    return size;
}

void initialize_dictionary(Dictionary &dico)
{
    const char *file = "./dico.txt";
    dico.lenght = count(file);
    dico.words = new Item[dico.lenght];

    for (unsigned int i = 0; i < dico.lenght; i++)
        dico.words[i] = new char[NB_CHAR_MAX];
}

void delete_dictionary(Dictionary &dico)
{
    for (unsigned int i = 0; i < dico.lenght; i++)
        delete[] dico.words[i];
    delete[] dico.words;
    dico.words = NULL;
}

void write(Dictionary &dico)
{
    ifstream in("./dico.txt");
    char word[NB_CHAR_MAX];

    int i = 0;
    while (in >> setw(NB_CHAR_MAX) >> word)
    {
        my_strcpy(dico.words[i], word);
        i++;
    }
    in.close();

    //debug

    cout << "dico.lenght = " << dico.lenght << endl;
    cout << "first word = " << dico.words[0] << endl;
    cout << "last word = " << dico.words[dico.lenght - 1] << endl;
}

bool dichotomy(Dictionary &dico, Item elem)
{
    unsigned int start = 0, end = dico.lenght, middle = (start + end) / 2;

    while (start < end) {
        if (my_strcmp(dico.words[middle], elem) == 0)
            return true;
        else if (my_strcmp(dico.words[middle], elem) > 0)
            end = middle - 1;
        else
            start = middle + 1;
        middle = (start + end) / 2;
    }
    return false;
    
}