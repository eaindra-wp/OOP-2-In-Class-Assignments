/*
    CH08-320143
    a2-p4.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <iostream>
#include <cstdio>
#include <cassert>
template <class T>
class linkedList
{
    class Link
    {
    public:
        T data;
        Link *next;
        Link *prev;
    };
    Link *init;
    int d_size;

public:
    //default constructor
    linkedList()
    {
        this->init = NULL;
        this->d_size = 0;
    }
    //copy constructor
    linkedList(const linkedList& l)
    {
        this->init = l.init;
        this->d_size = l.d_size;
    }
    //destructor
    ~linkedList()
    {
        delete this->init;
        this->d_size = 0;
    }

    //add the element at the back
    void pushback(T dat)
    {
        if(this->init == NULL)
        {
            this->init = new Link();
            this->init->prev = NULL;
            this->init->next = NULL;
            this->init->data = dat;
            this->d_size++;
        }
        else
        {
            Link *curr = this->init;
            while(curr->next != NULL)
                curr = curr->next;
            curr->next = new Link();
            curr->next->prev = curr;
            curr->next->next = NULL;
            curr->next->data = dat;
            this->d_size++;
        }
    }
    //push the new element to the front
    void pushfront(T dat)
    {
        if(this->init == NULL)
        {
            this->init = new Link();
            this->init->prev = NULL;
            this->init->next = NULL;
            this->init->data = dat;
            this->d_size++;
        }
        else
        {
            Link *nl = new Link();
            nl->prev = NULL;
            nl->next = this->init;
            //add the data to the front
            nl->data = dat;
            this->init->prev = nl;
            this->init = nl;
            this->d_size++;
        }
    }
    //return element in the beginning of list
    T front()
    {
        assert(this->init != NULL);
        return this->init->data;
    }

   //return element at the end of list
    T back()
    {
        assert(this->init != NULL);
        Link *curr = this->init;
        while(curr->next != NULL)
            curr = curr->next;
        return curr->data;
    }
    /*return the element from the back of
    list and remove from the list*/
    T popback()
    {
        assert(this->init != NULL);
        Link *cur = this->init;
        //move the cursor to the back
        while(cur->next != NULL)
            cur = cur->next;

        T res = cur->data;
        Link *tmp = cur;
        this->d_size--;
        if(this->d_size == 0)
        {
            this->init = NULL;
        }
        else
        {
            Link *prev = cur->prev;
            prev->next = NULL;
            delete tmp;
        }
        return res;
    }
    /*return the front element and remove
    from the list*/
    T popfront()
    {
        assert(this->init != NULL);
        T res = this->init->data;
        Link *tmp = this->init;
        //copy the frontmost element
        this->init = this->init->next;
        //move the pointer forwards
        delete tmp;
        //delete the element
        this->d_size--;
        if(this->d_size == 0)
        {
            this->init = NULL;
        }
        return res;
    }
    //return the size of the array
    int getSize()
    {
        return this->d_size;
    }
};

#endif // !_LINKEDLIST_H
