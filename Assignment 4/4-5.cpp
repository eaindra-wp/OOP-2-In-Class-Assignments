/*
    CH08-320143
    a4-p5.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream in;
    in.open("data.txt");
    //check the file status
    if(!in.good())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
    //initialize the map
    map<unsigned long,string> data;
    unsigned long matr;
    string name;
    //insert all data from the file to the map
    while(!in.eof())
    {
        in >> matr;
        in.ignore();
        //ignore the space after matr number
        getline(in,name);
        data[matr] = name;
        //map name with matr number
    }
    in.close();
    unsigned long input;
    //user input for matr number
    while(1)
    {
        cin >> input;
        //if user wants to stop checking
        if(input == 0)
            break;
        //not available matr number
        if(data.find(input) == data.end())
            cerr<<"Matriculation number not found"<<endl;
        else
            cout << data[input] << endl;
        cout << "Press 0 to quit!" << endl;
    }
    return 0;
}
