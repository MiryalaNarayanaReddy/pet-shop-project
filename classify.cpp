#include "classify.h"

void get_data(vector<Pet> &pets)
{
    ifstream file;
    file.open("database.txt");
    if (file.is_open())
        cout << "success\n";
    Pet curr_pet;
    string name;
    int cost;
    int number;

    while (file >> name)
    {
        file >> cost >> number;
        curr_pet.set_name(name);
        curr_pet.set_pet_count(number);
        curr_pet.set_cost(cost);
        pets.push_back(curr_pet);
    }
    file.close();
}
void search(vector<Pet> pets, Pet deal)
{
    cout << "SEARCH BY KIND: \n";
    for (int i = 0; i < pets.size(); i++)
    {
        if (pets[i].get_pet_name() == deal.get_pet_name())
        {
            display_pet(pets[i]);
            cout << endl;
        }
    }
    cout<<endl;
    cout << "SEARCH BY COST: \n";
    for (int i = 0; i < pets.size(); i++)
    {
        if (pets[i].get_cost() <= deal.get_cost())
        {
            display_pet(pets[i]);
        }
    }
    cout<<endl;
    cout << "SEARCH BY NUMBER AND COST: \n";
    for (int i = 0; i < pets.size(); i++)
    {
        if (pets[i].get_pet_count() >= deal.get_pet_count()&&pets[i].get_cost() <= deal.get_cost())
        {
            display_pet(pets[i]);
        }
    }
    cout<<endl;
}
void customer(vector<Pet> &pets)
{
    string name;
    int number;
    Pet deal;
    cout<<"your choice: \n"
    <<"KIND :   ";
     cin>>name;
     cout<<"NUMBER:   ";
     cin>>number;
     for(int i=0;i<pets.size();i++)
     {
         if(pets[i].get_pet_name()==name)
         {
            cout<<"TOTAL COST:  "<<pets[i].get_cost()*number<<endl;
            pets[i].set_pet_count(pets[i].get_pet_count()-number);
            cout<<"SUCCESS\n";
         }
     }
}
void buy(vector<Pet> &pets)
{
    string name;
    int affordable_cost;
    int number;
    Pet deal;
    cout << "What kind of pet do you want?\n";
    cin >> name;
    deal.set_name(name);
    cout << "How much can you afford?\n";
    cin >> affordable_cost;
    deal.set_cost(affordable_cost);
    cout << "how many do you want?\n";
    cin >> number;
    deal.set_pet_count(number);
    search(pets, deal);
    customer(pets);
}
void display_pet(Pet curr_pet)
{
    cout << "Name:   " << curr_pet.get_pet_name() << "  "
         << "Price:  " << curr_pet.get_cost() << "  "
         << "Number: " << curr_pet.get_pet_count() << "\n";
}
void print_all(vector<Pet> pets)
{
    ofstream file;
    file.open("database.txt");
    if (file.is_open())
        cout << "success" << endl;
    Pet curr_pet;
    for (int i = 0; i < pets.size(); i++)
    {
        curr_pet.set_name(pets[i].get_pet_name());
        curr_pet.set_cost(pets[i].get_cost());
        curr_pet.set_pet_count(pets[i].get_pet_count());
        file << curr_pet.get_pet_name() << "  " << curr_pet.get_cost() << "  " << curr_pet.get_pet_count() << "\n";
    }
    file.close();
}