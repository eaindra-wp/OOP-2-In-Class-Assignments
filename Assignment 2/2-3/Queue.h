/*
    CH08-320143
    a2-p3.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#include <cassert>
#include <iostream>
#ifndef _QUEUE_H
#define _QUEUE_H
template <class T>
class Queue
{
        T *prop;
        int q_size;
        int where;

    public:
        Queue()
        {
            this->q_size = 10;
            //initialize the size of queue as 10
            this->prop = new T[this->q_size];
            this->where = -1;
        }
        //copy constructor
        Queue(const Queue& obj)
        {
            this->q_size = obj.q_size;
            this->prop = new T[this->where];
            for(int i=0; i<this->q_size; i++)
                this->prop[i] = obj.prop[i];
            this->where = obj.where;
        }
        //set the given size for the queue
        Queue(int size)
        {
            this->prop = new T[size];
            this->q_size = size;
            this->where = -1;
        }
        //destructor
        ~Queue()
        {
            delete []this->prop;
            this->q_size = 0;
            this->where = -1;
        }
        bool push(T element)
        {
            if(this->where+1 == this->q_size)
                return false;
            this->prop[++this->where] = element;
            return true;
        }
        bool pop(T& out)
        {
            if(this->where == -1)
                return false;
            out = this->prop[0];
            for(int i=0; i<this->q_size; i++)
                this->prop[i] = this->prop[i+1];
            this->where--;
            return true;
        }
        //return the element at the end of queue
        T back()
        {
            assert(this->where >= 0);
            return this->prop[this->where];
        }
        //return the element in the beginning
        T front()
        {
            assert(this->where >= 0);
            return this->prop[0];
        }
        //get the number of entries
        int getNumEntries()
        {
            return (this->where+1);
        }
        //resizing the queue
        void resize(int size)
        {
            T *newp = new T[size];
            //copy existing elements according to the size
            //given to the new array
            for(int i=0; i<std::min(this->where,size); i++)
                newp[i] = this->prop[i];

            //deallocate the existing array
            delete []this->prop;
            this->prop = newp;
            this->q_size = size;
            this->where = std::min(this->where,size-1);
        }
        //return the size of the queue
        int getSize()
        {
            return this->q_size;
        }
};
#endif // _QUEUE_H
