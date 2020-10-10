#pragma once
#include <ostream>
#include <iostream>
#include "node.h"

using namespace std;
class linkList
{
private:
    node* hearPtr;
    node* lastPtr;

public:
    node * getHead()const;
    node * getLast()const;
    void setHead(node * p);
    void setLast(node * p);
    bool isEmpty()const;
    int getSize() const;
    node * getNode(const int & pos)const;
    void insertAtFront(const int & value);
    void insertAtBack(const int & value);
    void insertAt(const int & value,const int & pos);
    void clear();
    node * removeAtFront();
    node * removeAtBack();
    node * removeAt(const int & pos);
    node * remove(const int & value);
    int getPosition(const int & value);
    int getFrequency(const int & value)const;
    bool find(const int & value)const;
    friend ostream & operator << (ostream & os, const linkList & list);
    linkList(/* args */);
    ~linkList();
};

ostream & operator << (ostream & os, const linkList & list){
    
    os << "{";
    node * checkPtr = list.getHead();
    while(checkPtr != 0){
        os << checkPtr -> getData(); 
        checkPtr = checkPtr -> getLink();
        
    }
    
    os << "}" << endl;

}

bool linkList::find(const int & value)const{
    bool found = false;
    node * checkPtr = hearPtr;
    while(checkPtr != 0){
        if(value == checkPtr -> getData())
            found = true;
        checkPtr = checkPtr -> getLink();
    }
    return found;
}

int linkList::getFrequency(const int & value)const{
    int feq = 0;
    node * checkPtr = hearPtr;
    while(checkPtr != 0){
        if(value == checkPtr -> getData())
            feq++;
        checkPtr = checkPtr -> getLink();
    }
    return feq;
}

int linkList::getPosition(const int & value){
    int pos = 1;
    bool found = false;
    node *  checkPtr = hearPtr;
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

node * linkList::remove(const int & value){
    node * tmpPtr = hearPtr;
    int pos = getPosition(value);
    if(pos > 0)
        tmpPtr = remove(pos);
    else
        tmpPtr = 0;
    return tmpPtr;
}

node * linkList::removeAt(const int & pos){
    node * tmpPtr = 0;
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
        node * checkNode = getNode(pos - 1);
        tmpPtr = getNode(pos);
        checkNode -> setLink(tmpPtr -> getLink());
    }
    return tmpPtr;
}
node * linkList::removeAtFront(){
    node * tmpPtr = hearPtr;
    if(isEmpty())
        return 0;
    else if(hearPtr == lastPtr)
        hearPtr = lastPtr = 0;
    else
        hearPtr = hearPtr -> getLink();
    return tmpPtr;
}

node * linkList::removeAtBack(){
    node * tmpPtr = lastPtr;
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

linkList::linkList(/* args */):hearPtr(0),lastPtr(0)
{
}

linkList::~linkList()
{
    clear();
}

void linkList::clear(){
    node *  tmpPtr = hearPtr;
    while(hearPtr != 0){
        hearPtr = hearPtr -> getLink();
        tmpPtr -> setLink(0);
        delete tmpPtr;
        tmpPtr = hearPtr;
        }
    

}
node * linkList::getHead()const {return hearPtr;}
node * linkList::getLast()const {return lastPtr;}
void linkList::setHead(node * p){hearPtr = p;}
void linkList::setLast(node * p){lastPtr = p;}
bool linkList::isEmpty()const{return hearPtr == 0;}
void linkList::insertAtFront(const int & value){
    node * newNodePtr = new node();
    newNodePtr -> setData(value);
    if(isEmpty()){
        hearPtr = lastPtr = newNodePtr;
    }
    else{
        newNodePtr -> setLink(hearPtr);
        hearPtr = newNodePtr ;
    }
}
void linkList::insertAtBack(const int & value){
    node * newNodePtr = new node();
    newNodePtr -> setData(value);
    if(isEmpty()){
        hearPtr = lastPtr = newNodePtr;
    }
    else{
        lastPtr -> setLink(newNodePtr);
        lastPtr = newNodePtr ;
    }
}
void linkList::insertAt(const int & value,const int & pos){
    if(pos == 1){
        insertAtFront(value);
    }
    else if(pos == getSize() + 1){
        insertAtBack(value);
    }
    else
    {
        node * newNodePtr = new node();
        newNodePtr -> setData(value);
        node * checkNode = getNode(pos - 1);
        newNodePtr -> setLink(checkNode -> getLink());
        checkNode -> setLink(newNodePtr);
    }
}
int linkList::getSize()const{
    node * curPtr = hearPtr;
    int i = 0;
    while(curPtr != 0){
        curPtr = curPtr -> getLink();
        i++;
    }
    return i;
}
node * linkList::getNode(const int & pos)const{
    node * checkPtr = hearPtr;
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