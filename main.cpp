#include "include/lib.h"
#include <iostream>
using namespace std;

int main(int ac, char *av[])
{
    int a = 5;
    int b = 10;

    my_swap(a, b);

    cout << a << endl;

    char *str = "Coucou";
    char *str2 = "42";

    my_swap(str, str2);

    cout << str << endl;
}
