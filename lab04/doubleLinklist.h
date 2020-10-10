#pragma once
#include "nodeDouble.h"



class doubleLinklist  
{
private:
    nodeDouble * headPtr;
    nodeDouble * lastPtr; 
public:
    bool isEmpty()const;
    nodeDouble * getPointerTo(const int & pos)const; //getNode from number 
    int getPostion(const int & value)const;
    int getSize()const;
    int getFeqof(const int & value)const;
    bool find(const int & value)const;
    void insertAtFront(const int & value);
    void insertAtBack(const int & value);
    void insert(const int & value , const int & pos);
    nodeDouble * removeAtFront();
    nodeDouble * removeAtBack();
    nodeDouble * removeAt(const int & pos);
    friend ostream & operator << (ostream & os, const doubleLinklist & list);
    doubleLinklist(/* args */);
    ~doubleLinklist();
};
ostream & operator << (ostream & os, const doubleLinklist & list){
    os << "{";
    nodeDouble * checkPtr = list.headPtr;
    while(checkPtr != 0){
        os << checkPtr -> getData(); 
        checkPtr = checkPtr -> getNext();
        
    }
    
    os << "}" << endl;
}

doubleLinklist::doubleLinklist(/* args */):headPtr(0),lastPtr(0)
{
}

doubleLinklist::~doubleLinklist()
{
}
bool doubleLinklist::isEmpty()const{
    return headPtr == NULL;
}
nodeDouble * doubleLinklist::getPointerTo(const int & pos)const{
    nodeDouble * tempPtr = headPtr;
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
int doubleLinklist::getPostion(const int & value)const{
    if (isEmpty())
    {
        printf("Error");
        system("pause");
    }
    else
    {
        nodeDouble * temp = headPtr;
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

int doubleLinklist::getSize()const{
    nodeDouble * curPtr = headPtr;
    int i = 0;
    while(curPtr != 0){
        curPtr = curPtr -> getNext();
        i++;
    }
    return i;
}
int doubleLinklist::getFeqof(const int & value)const{
    int feq = 0;
    nodeDouble * checkPtr = headPtr;
    while(checkPtr != 0){
        if(value == checkPtr -> getData())
            feq++;
        checkPtr = checkPtr -> getNext();
    }
    return feq;
}
bool doubleLinklist::find(const int & value)const{
    bool found = false;
    nodeDouble * checkPtr = headPtr;
    while(checkPtr != 0){
        if(value == checkPtr -> getData())
            found = true;
        checkPtr = checkPtr -> getNext();
    }
    return found;
}

void doubleLinklist::insertAtFront(const int & value){
    nodeDouble * temp = new nodeDouble();
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
void doubleLinklist::insertAtBack(const int & value){
    nodeDouble * temp = new nodeDouble();
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
void doubleLinklist::insert(const int & value, const int & pos){
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
        nodeDouble * temp = new nodeDouble();
        temp -> setData(value);
        //nodeDouble * next = getPointerTo(pos - 1);
       // nodeDouble * prev = getPointerTo(pos + 1);
        temp -> setNext(getPointerTo(pos - 1));
        temp -> setPrev(getPointerTo(pos + 1));
        getPointerTo(pos - 1) ->setNext(temp);
        getPointerTo(pos + 1) ->setPrev(temp);
        
    }
}
nodeDouble * doubleLinklist::removeAtFront(){
nodeDouble * tmpPtr = headPtr;
    if(isEmpty())
        return 0;
    else if(headPtr == lastPtr)
        headPtr = lastPtr = 0;
    else
        headPtr = headPtr -> getNext();
    return tmpPtr;
}
nodeDouble * doubleLinklist::removeAtBack(){
    nodeDouble * tmpPtr = lastPtr;
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
nodeDouble * doubleLinklist::removeAt(const int & pos){
    nodeDouble * tmpPtr = 0;
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
