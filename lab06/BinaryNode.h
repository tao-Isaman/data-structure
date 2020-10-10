#include <iostream>
#pragma once
using namespace std;

template<class T>
class BinaryNode;

/* template<class T>
std::ostream & operator << (std::ostream &,const BinaryNode<T> &); */

template<class T>
class BinaryNode
{
private:
    T data;
    BinaryNode<T> * left;
    BinaryNode<T> * right; 


    /* data */
public:
    BinaryNode(/* args */);
    BinaryNode(const T & val);
    BinaryNode(const T & val , BinaryNode<T> * l , BinaryNode<T> * r);
    void setData(const T & val);
    void setLeft(BinaryNode<T> * l);
    void setRight(BinaryNode<T> * r);
    T getData();
    BinaryNode<T>* getLeft() const;
    BinaryNode<T>* getRight() const;
    void nodeDisplay() ;
   // friend std::ostream & operator << <T> (std::ostream & os,const BinaryNode<T> & bn);
};

/* template<class T>
std::ostream & operator << <T> (std::ostream & os,const BinaryNode<T> & bn){
os <<bn.data;
return os;

} */

template<class T>
void BinaryNode<T>::nodeDisplay(){
cout << getData();
}



template<class T>
BinaryNode<T>::BinaryNode(/* args */):left(NULL),right(NULL)
{
}
template<class T>
BinaryNode<T>::BinaryNode(const T & val):data(val),left(NULL),right(NULL)
{
}
template<class T>
BinaryNode<T>::BinaryNode(const T & val , BinaryNode<T> * l , BinaryNode<T> * r):data(val),right(r),left(l)
{
}


template<class T>
void BinaryNode<T>::setData(const T& val){data = val;}
template<class T>
void BinaryNode<T>::setRight(BinaryNode<T> * r){right = r;}
template<class T>
void BinaryNode<T>::setLeft(BinaryNode<T> * l){left = l;}
template<class T>
T BinaryNode<T>::getData(){return data;}
template<class T>
BinaryNode<T>* BinaryNode<T>::getLeft() const{
    return left;
}
template<class T>
BinaryNode<T>* BinaryNode<T>::getRight() const{
    return right;
}
