#include "menu.h"
#include "classify.h"

char display_menu()
{
    char ch;
    cout << "buy     B\n"
         << "add     A\n"
         << "quit     Q\n";
    cin >> ch;
    return ch;
}

void perform_action(char option)
{

    switch (option)
    {
    case 'B':
    {
        vector<Pet> pets;
        get_data(pets);
        buy(pets);
        print_all(pets);
        break;
    }
    case 'A':
        //increment the count
        break;
    case 'Q':
        cout << "THANK YOU\n";
        break;
    }
}