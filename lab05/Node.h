#pragma once
#include <iostream> 
using namespace std;

template<class T> class Node;
/* template<class T> 
ostream& operator<<(ostream&, const Node<T>&);  */
template<class T>
class Node {  
    private: 
     T data; 
     Node<T> * link; 
    public: 
     Node();
     Node(const T & aData);
     T getData()const;
     Node<T>* getLink()const;
     void setData(const T & aData);
     void setLink(Node<T>* next);
     void display();
     //friend ostream & operator<<<T>(ostream & os, const Node<T> & n); 
};

template<class T> 
Node<T>::Node() : link(0) {}

template<class T> 
Node<T>::Node(const T& aData) : data(aData), link(0) {} 

template<class T>
T Node<T>::getData() const { return data; }

template<class T>
Node<T>* Node<T>::getLink() const { return link; } 

template<class T>
void Node<T>::setData(const T & aData) { data = aData; } 

template<class T> 
void Node<T>::setLink(Node* next) { link = next; } 

//this function is not allow " error: function template partial specialization 'operator<< <T>' is not allowed "
/* template<class T> 
 ostream & operator<<<T>(ostream & os, const Node<T> & n){
    os << n.getData(); 
    return os; 
 } */

template<class T> 
void Node<T>::display(){
    cout << getData() ;
}






