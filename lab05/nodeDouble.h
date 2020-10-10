#pragma once
#include <iostream>
using namespace std;
template<class T> class nodeDouble;

template<class T>
class nodeDouble
{
private:
    T data;
    nodeDouble<T> * next;
    nodeDouble<T> * prev;

public:
    T getData()const;
    void setData(const T & value);
    nodeDouble<T> * getNext()const;
    void setNext(nodeDouble<T> * node);
    nodeDouble<T> * getPrev()const;
    void setPrev(nodeDouble<T> * node);
    void nodeDoubleDisplay();
    //friend  ostream & operator << (ostream & os , const nodeDouble & n);
    nodeDouble(/* args */);
    nodeDouble(const T & aData);
};
template<class T>
void nodeDouble<T>::nodeDoubleDisplay(){
    cout << getData();
}

/* ostream & operator << (ostream & os , const nodeDouble & n){
    os << n.data ;
} */

template<class T>
nodeDouble<T>::nodeDouble(/* args */):next(0),prev(0)
{
}

template<class T>
nodeDouble<T>::nodeDouble(const T & aData):data(aData),next(0),prev(0)
{
}
template<class T>
T nodeDouble<T>::getData()const{
return data;
}
template<class T>
nodeDouble<T> * nodeDouble<T>::getNext()const{
return next;
}
template<class T>
nodeDouble<T> * nodeDouble<T>::getPrev()const{
return prev;
}
template<class T>
void nodeDouble<T>::setData(const T & value){
    data = value;
}
template<class T>
void nodeDouble<T>::setNext(nodeDouble<T> * node){
    next = node;
}
template<class T>
void nodeDouble<T>::setPrev(nodeDouble<T> * node){
    prev = node;
}