/*
    CH08-320143
    a3-p6.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
class Fruit
{
private:
    string name;
    int price;
public:
    //parametric constructor
    Fruit(string n, int p)
    {
        this->name = n;
        this->price = p;
    }
    //overload << operator to put name and price
    friend ostream& operator<<(ostream& os,
                               const Fruit& f)
    {
        os << f.name << " ";
        os << f.price << endl;
        return os;
    }
    //overload < operator to sort in
    //max heap format
    bool operator<(const Fruit& f) const
    {
        return (this->price < f.price);
    }
};
struct compare
{
public:
    //to sort elements in descending order
    bool operator()(const int& l,const int& r)const
    {
        return (l<r);
    }
};
int main()
{
    priority_queue<int> pq;
    int ilist[] = {5,8,4,2,9,3,7};
    for(int i=0; i<7; i++)
        pq.push(ilist[i]);
    //push integers into the priority queue

    cout<<"Testcase 1"<<endl;
    cout<<"Priority queue size: "<<pq.size()<<endl;

    //pop and print elements from p_queue
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n" << endl;

    priority_queue<Fruit> fq;
    cout << "Testcase 2" << endl;
    //push fruit names and prices
    fq.push(Fruit("Apple",2));
    fq.push(Fruit("Orange",1));
    fq.push(Fruit("Banana",3));
    cout<<"Priority queue size: "<<fq.size()<<endl;
    //pop elements and print
    while(!fq.empty())
    {
        cout << fq.top();
        fq.pop();
    }
    cout << endl;

    cout << "Testcase 3" << endl;
    priority_queue<int,vector<int>,compare> cmp;
    for(int i=0; i<5; i++)
        cmp.push(i);
    cout<<"Priority queue size: "<<cmp.size()<<endl;
    while(!cmp.empty())
    {
        cout << cmp.top() << " ";
        cmp.pop();
    }
    cout << "\n" << endl;
    return 0;
}
