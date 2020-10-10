#pragma once
#include "linklist.h"

template<class T>
class linkQueue;

template<class T>
class linkQueue : public linklist<T>
{
private:
    /* data */
public:
    void enqueue(const T & value);
    Node<T> * dequeue();
    bool find(const T & value);
    bool isEmpty()const;
    void QueueDisplay();
    
    linkQueue(/* args */);
    ~linkQueue();
};

template<class T>
void linkQueue<T>::QueueDisplay(){
    linklist<T>::linkDisplay();
}

template<class T>
linkQueue<T>::linkQueue(/* args */):linklist<T>()
{
}

template<class T>
linkQueue<T>::~linkQueue()
{
    //clear();
}
template<class T>
void linkQueue<T>::enqueue(const T & value){
    linklist<T>::insertAtBack(value);
}
template<class T>
Node<T> * linkQueue<T>::dequeue(){
    return linklist<T>::removeAtFront();
}
template<class T>
bool linkQueue<T>::find(const T & value){
    return linklist<T>::find(value);
}
template<class T>
bool linkQueue<T>::isEmpty()const{
    return linklist<T>::isEmpty();
}