#pragma once
#include "nodeDouble.h"

template <class T>
class doubleLinklist ;


template <class T>
class doubleLinklist  
{
private:
    nodeDouble<T> * headPtr;
    nodeDouble<T> * lastPtr; 
public:
    bool isEmpty()const;
    nodeDouble<T> * getPointerTo(const int & pos)const; //getNode from number 
    int getPostion(const T & value)const;
    int getSize()const;
    int getFeqof(const T & value)const;
    bool find(const T & value)const;
    void insertAtFront(const T & value);
    void insertAtBack(const T & value);
    void insert(const T & value , const int & pos);
    nodeDouble<T> * removeAtFront();
    nodeDouble<T> * removeAtBack();
    nodeDouble<T> * removeAt(const int & pos);
    void linkDisplay();
   // friend ostream & operator << (ostream & os, const doubleLinklist & list);
    doubleLinklist(/* args */);
    ~doubleLinklist();
};

/* ostream & operator << (ostream & os, const doubleLinklist & list){
    os << "{";
    nodeDouble * checkPtr = list.headPtr;
    while(checkPtr != 0){
        os << checkPtr -> getData(); 
        checkPtr = checkPtr -> getNext();
        
    }
    
    os << "}" << endl;
} */
template <class T>
void doubleLinklist<T>::linkDisplay(){
    cout << "{";
    nodeDouble<T> * checkPtr = headPtr;
    while (checkPtr != 0)
    {
        cout << checkPtr -> getData();
        checkPtr = checkPtr -> getNext();
    }
    cout << "}" << endl;
    
}


template <class T>
doubleLinklist<T>::doubleLinklist(/* args */):headPtr(0),lastPtr(0)
{
}

template <class T>
doubleLinklist<T>::~doubleLinklist()
{
}
template <class T>
bool doubleLinklist<T>::isEmpty()const{
    return headPtr == NULL;
}
template <class T>
nodeDouble<T> * doubleLinklist<T>::getPointerTo(const int & pos)const{
    nodeDouble<T> * tempPtr = headPtr;
    if(isEmpty() || pos > getSize()){
        tempPtr = 0;
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            tempPtr = tempPtr -> getNext();
        }      
    }
    return tempPtr;
}
template <class T>
int doubleLinklist<T>::getPostion(const T & value)const{
    if (isEmpty())
    {
        printf("Error");
        system("pause");
    }
    else
    {
        nodeDouble<T> * temp = headPtr;
       // int pos;
        int i;
        for ( i = 0; i < getSize(); i++)
        {
            if (temp -> getData() == value)
            {
                return i;
            }
            else
            {
                temp = temp -> getNext();
            }
        }
    }
   // return i;
}

template <class T>
int doubleLinklist<T>::getSize()const{
    nodeDouble<T> * curPtr = headPtr;
    int i = 0;
    while(curPtr != 0){
        curPtr = curPtr -> getNext();
        i++;
    }
    return i;
}
template <class T>
int doubleLinklist<T>::getFeqof(const T & value)const{
    int feq = 0;
    nodeDouble<T> * checkPtr = headPtr;
    while(checkPtr != 0){
        if(value == checkPtr -> getData())
            feq++;
        checkPtr = checkPtr -> getNext();
    }
    return feq;
}
template <class T>
bool doubleLinklist<T>::find(const T & value)const{
    bool found = false;
    nodeDouble<T> * checkPtr = headPtr;
    while(checkPtr != 0){
        if(value == checkPtr -> getData())
            found = true;
        checkPtr = checkPtr -> getNext();
    }
    return found;
}

template <class T>
void doubleLinklist<T>::insertAtFront(const T & value){
    nodeDouble<T> * temp = new nodeDouble<T>();
    temp -> setData(value);
    if (isEmpty())
    {
        headPtr = lastPtr = temp;
    }
    else
    {
        temp ->setNext(headPtr);
        headPtr -> setPrev(temp);
        headPtr = temp;
    } 
}
template <class T>
void doubleLinklist<T>::insertAtBack(const T & value){
    nodeDouble<T> * temp = new nodeDouble<T>();
    temp -> setData(value);
    if (isEmpty())
    {
        headPtr = lastPtr = temp;
    }
    else
    {
        temp -> setPrev(lastPtr);
        lastPtr -> setNext(temp);
        lastPtr = temp;
    }
}
template <class T>
void doubleLinklist<T>::insert(const T & value, const int & pos){
    if (pos == 1)
    {
        insertAtFront(value);
    }
    else if (pos == getSize() + 1)
    {
        insertAtBack(value);
    }
    else
    {
        nodeDouble<T> * temp = new nodeDouble<T>();
        temp -> setData(value);
        //nodeDouble * next = getPointerTo(pos - 1);
       // nodeDouble * prev = getPointerTo(pos + 1);
        temp -> setNext(getPointerTo(pos - 1));
        temp -> setPrev(getPointerTo(pos + 1));
        getPointerTo(pos - 1) ->setNext(temp);
        getPointerTo(pos + 1) ->setPrev(temp);
        
    }
}
template <class T>
nodeDouble<T> * doubleLinklist<T>::removeAtFront(){
nodeDouble<T> * tmpPtr = headPtr;
    if(isEmpty())
        return 0;
    else if(headPtr == lastPtr)
        headPtr = lastPtr = 0;
    else
        headPtr = headPtr -> getNext();
    return tmpPtr;
}
template <class T>
nodeDouble<T> * doubleLinklist<T>::removeAtBack(){
    nodeDouble<T> * tmpPtr = lastPtr;
    if(isEmpty())
        return 0;
    else if(headPtr == lastPtr)
        headPtr = lastPtr = 0;
    else{
        lastPtr = getPointerTo(getSize()-1);
        lastPtr -> setNext(0);
    } 
    return tmpPtr;
}
template <class T>
nodeDouble<T> * doubleLinklist<T>::removeAt(const int & pos){
    nodeDouble<T> * tmpPtr = 0;
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
        //nodeDouble * checkNode = getPointerTo(pos - 1);
        //nodeDouble * checkNode2 = getPointerTo(pos - 1);
        getPointerTo(pos - 1) -> setNext(getPointerTo(pos + 1));
        getPointerTo(pos + 1) -> setPrev(getPointerTo(pos - 1));
        tmpPtr = getPointerTo(pos);
    }
    return tmpPtr;
}
