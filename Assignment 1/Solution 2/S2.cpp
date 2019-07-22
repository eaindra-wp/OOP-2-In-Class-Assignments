/*
    CH08-320143
    a1-p2.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;
//to open input files
void open(string fname, ifstream& in)
{
    const char *f = fname.c_str();
    if(!in.is_open())
    {
        in.open(f, ios::in|ios::binary);
    }
}
//get the length of contents in each file
int file_length(ifstream &in)
{
    in.seekg(0, ios::end);
    int l = in.tellg();
    in.seekg(0, ios::beg);
    return l;
}
int main()
{
    int n,i;
    cin >> n;
    string name[n];
    //read file names
    for(i=0; i<n; i++)
    {
        cin >> name[i];
    }
    ofstream out("concatn.txt",ios::out|ios::binary);
    //open output file
    if(!out.good())
    {
        cerr << "Error opening output file" << endl;
        exit(1);
    }
    for(i=0; i<n; i++)
    {
        ifstream in;
        open(name[i],in);
        //open one input file
        //the others will be opened after each iteration
        if(!in.good())
        {
            cerr << "Error opening input file" << endl;
            exit(2);
        }
        int l = file_length(in);
        /*read contents from the input file
        and add to a char array*/
        char* buf = new char[l+1];
        in.read(buf,l);
        buf[l] = '\n';
        out.write(buf,l+1);
        //write in the output file
        delete []buf;
        in.close();
    }
    return 0;
}
