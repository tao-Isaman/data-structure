#pragma once
#include <ostream>
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class linklist;



template <class T>
class linklist 
{
private:
    Node<T>* hearPtr;
    Node<T>* lastPtr;

public:
    Node<T> * getHead()const;
    Node<T> * getLast()const;
    void setHead(Node<T> * p);
    void setLast(Node<T> * p);
    bool isEmpty()const;
    int getSize() const;
    Node<T> * getNode(const int & pos)const;
    void insertAtFront(const T & value);
    void insertAtBack(const T & value);
    void insertAt(const T & value,const int & pos);
    void clear();
    Node<T> * removeAtFront();
    Node<T> * removeAtBack();
    Node<T> * removeAt(const int & pos);
    Node<T> * remove(const int & value);
    int getPosition(const int & value);
    int getFrequency(const int & value)const;
    bool find(const int & value)const;
    void linkDisplay();
    
    linklist(/* args */);
    ~linklist();
};

//this function is not allow " error: function template partial specialization 'operator<< <T>' is not allowed "
/* template <class T>
ostream & operator << (ostream & os, const linklist<T> & list){
    
    os << "{";
    Node<T> * checkPtr = list.getHead();
    while(checkPtr != 0){
        os << checkPtr -> getData(); 
        checkPtr = checkPtr -> getLink();
        
    }
    
    os << "}" << endl;

} */
template <class T>
void linklist<T>::linkDisplay(){
    cout << "{";
    Node<T> * checkPtr = getHead();
    while (checkPtr != 0)
    {
        cout << checkPtr -> getData();
        checkPtr = checkPtr -> getLink();
    }
    cout << "}" << endl;

}


template <class T>
bool linklist<T>::find(const int & value)const{
    bool found = false;
    Node<T> * checkPtr = hearPtr;
    while(checkPtr != 0){
        if(value == checkPtr -> getData())
            found = true;
        checkPtr = checkPtr -> getLink();
    }
    return found;
}

template <class T>
int linklist<T>::getFrequency(const int & value)const{
    int feq = 0;
    Node<T> * checkPtr = hearPtr;
    while(checkPtr != 0){
        if(value == checkPtr -> getData())
            feq++;
        checkPtr = checkPtr -> getLink();
    }
    return feq;
}

template <class T>
int linklist<T>::getPosition(const int & value){
    int pos = 1;
    bool found = false;
    Node<T> *  checkPtr = hearPtr;
    while(!found && (checkPtr != 0)){
        if(value == checkPtr -> getData())
            found = true;
        else
            checkPtr = checkPtr -> getLink();
        ++pos;
    }
    if(!found)
        pos = 0;

    return pos;
}

template <class T>
Node<T> * linklist<T>::remove(const int & value){
    Node<T> * tmpPtr = hearPtr;
    int pos = getPosition(value);
    if(pos > 0)
        tmpPtr = remove(pos);
    else
        tmpPtr = 0;
    return tmpPtr;
}

template <class T>
Node<T> * linklist<T>::removeAt(const int & pos){
    Node<T> * tmpPtr = 0;
    if(isEmpty() || pos > getSize())
        tmpPtr = 0;
    else if(pos == 1){
        tmpPtr = removeAtFront();
    }
    else if(pos == getSize() + 1){
        tmpPtr = removeAtBack();
    }
    else
    {
        Node<T> * checkNode = getNode(pos - 1);
        tmpPtr = getNode(pos);
        checkNode -> setLink(tmpPtr -> getLink());
    }
    return tmpPtr;
}

template <class T>
Node<T> * linklist<T>::removeAtFront(){
    Node<T> * tmpPtr = hearPtr;
    if(isEmpty())
        return 0;
    else if(hearPtr == lastPtr)
        hearPtr = lastPtr = 0;
    else
        hearPtr = hearPtr -> getLink();
    return tmpPtr;
}

template <class T>
Node<T> * linklist<T>::removeAtBack(){
    Node<T> * tmpPtr = lastPtr;
    if(isEmpty())
        return 0;
    else if(hearPtr == lastPtr)
        hearPtr = lastPtr = 0;
    else{
        lastPtr = getNode(getSize()-1);
        lastPtr -> setLink(0);
    }
        
    return tmpPtr;
}

template <class T>
linklist<T>::linklist(/* args */):hearPtr(0),lastPtr(0)
{
}

template <class T>
linklist<T>::~linklist()
{
    clear();
}

template <class T>
void linklist<T>::clear(){
    Node<T> *  tmpPtr = hearPtr;
    while(hearPtr != 0){
        hearPtr = hearPtr -> getLink();
        tmpPtr -> setLink(0);
        delete tmpPtr;
        tmpPtr = hearPtr;
        }
    

}

template <class T>
Node<T> * linklist<T>::getHead()const {return hearPtr;}
template <class T>
Node<T> * linklist<T>::getLast()const {return lastPtr;}
template <class T>
void linklist<T>::setHead(Node<T> * p){hearPtr = p;}
template <class T>
void linklist<T>::setLast(Node<T> * p){lastPtr = p;}
template <class T>
bool linklist<T>::isEmpty()const{return hearPtr == 0;}
template <class T>
void linklist<T>::insertAtFront(const T & value){
    Node<T> * newNodePtr = new Node<T>();
    newNodePtr -> setData(value);
    if(isEmpty()){
        hearPtr = lastPtr = newNodePtr;
    }
    else{
        newNodePtr -> setLink(hearPtr);
        hearPtr = newNodePtr ;
    }
}

template <class T>
void linklist<T>::insertAtBack(const T & value){
    Node<T> * newNodePtr = new Node<T>();
    newNodePtr -> setData(value);
    if(isEmpty()){
        hearPtr = lastPtr = newNodePtr;
    }
    else{
        lastPtr -> setLink(newNodePtr);
        lastPtr = newNodePtr ;
    }
}

template <class T>
void linklist<T>::insertAt(const T & value,const int & pos){
    if(pos == 1){
        insertAtFront(value);
    }
    else if(pos == getSize() + 1){
        insertAtBack(value);
    }
    else
    {
        Node<T> * newNodePtr = new Node<T>();
        newNodePtr -> setData(value);
        Node<T> * checkNode = getNode(pos - 1);
        newNodePtr -> setLink(checkNode -> getLink());
        checkNode -> setLink(newNodePtr);
    }
}
template <class T>
int linklist<T>::getSize()const{
    Node<T> * curPtr = hearPtr;
    int i = 0;
    while(curPtr != 0){
        curPtr = curPtr -> getLink();
        i++;
    }
    return i;
}
template <class T>
Node<T> * linklist<T>::getNode(const int & pos)const{
    Node<T> * checkPtr = hearPtr;
    int i = 0;
    if(isEmpty() || pos > getSize()){
            checkPtr = 0;
    }
    else{
        for( i = 0; i < pos; i++)
        {
            checkPtr = checkPtr -> getLink();
        }
    }
    return checkPtr;
}


