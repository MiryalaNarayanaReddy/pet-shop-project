#ifndef _CLASSIFY_H_
#define _CLASSIFY_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Pet
{
private:
    string pet_name;
    double price;
    int number_of_pets;

public:
    void set_name(string name)
    {
        pet_name = name;
    }
    void set_pet_count(int c)
    {
        number_of_pets = c;
    }
    string get_pet_name()
    {
        return pet_name;
    }
    int get_pet_count()
    {
        return number_of_pets;
    }
    void set_cost(int c)
    {
        price = c;
    }
    int get_cost()
    {
        return price;
    }
};
void get_data( vector<Pet> &pets);
void print_all( vector<Pet> pets);
void search(vector<Pet>pets,Pet deal);
void buy( vector<Pet> &pets);
void display_pet(Pet curr_pet);
void customer(vector<Pet> &pets);

#endif