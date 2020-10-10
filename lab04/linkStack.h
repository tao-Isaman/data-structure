#pragma once
#include "linkList.h"

class linkStack : public linkList
{
private:
    /* data */
public:
    bool isEmpty()const;   
    void push(const int & value); 
    node * pop();
    bool find(const int & value);

    friend ostream & operator << (ostream & os, const linkStack & list);
    linkStack(/* args */);
    ~linkStack();
};
ostream & operator << (ostream & os, const linkStack & list){
    linkList lst = list;
    os << lst;
    return os;

}


linkStack::linkStack(/* args */)
{
}

linkStack::~linkStack()
{
    clear();
}
bool linkStack::isEmpty()const {return linkList::isEmpty();}
void linkStack::push(const int & value){
    insertAtFront(value);
}
node * linkStack::pop(){
return removeAtFront();
}
bool linkStack::find(const int & valeu){
    return linkList::find(valeu);
}