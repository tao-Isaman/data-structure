#pragma once
#include "linkList.h"

class linkQueue : public linkList
{
private:
    /* data */
public:
    void enqueue(const int & value);
    node * dequeue();
    bool find(const int & value);
    bool isEmpty()const;
    friend ostream & operator << (ostream & os, const linkQueue & list);
    linkQueue(/* args */);
    ~linkQueue();
};
ostream & operator << (ostream & os, const linkQueue & list){
    linkList lst = list;
    os << lst;
    return os;

}

linkQueue::linkQueue(/* args */):linkList()
{
}

linkQueue::~linkQueue()
{
    clear();
}
void linkQueue::enqueue(const int & value){
    insertAtBack(value);
}
node * linkQueue::dequeue(){
    return removeAtFront();
}
bool linkQueue::find(const int & value){
    return linkList::find(value);
}
bool linkQueue::isEmpty()const{
    return linkList::isEmpty();
}