#pragma once 
#include "linklist.h"

template <class T>
class linkStack;




template<class T>
class linkStack : public linklist<T>
{
private:
    /* data */
public:
    bool isEmpty()const;   
    void push(const T & value); 
    Node<T> * pop();
    bool find(const T & value);
    void displayStack();

    linkStack(/* args */);
    ~linkStack();
};
template<class T>
void linkStack<T>::displayStack(){
    linklist<T>::linkDisplay();
}

template<class T>
linkStack<T>::linkStack(/* args */):linklist<T>()
{
}

template<class T>
linkStack<T>::~linkStack()
{
}

template<class T>
bool linkStack<T>::isEmpty()const {return linklist<T>::isEmpty();}

template<class T>
void linkStack<T>::push(const T & value){
    linklist<T>::insertAtFront(value);
}

template<class T>
Node<T> * linkStack<T>::pop(){
return linklist<T>::removeAtFront();
}

template<class T>
bool linkStack<T>::find(const T & valeu){
    return linklist<T>::find(valeu);
}




