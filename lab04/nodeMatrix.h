#pragma once
#include "nodeNumber.h"
using namespace std;


class nodeMatrix
{
private:
    int row;
    nodeNumber * next ;
    nodeMatrix * down ;
public:
    int getData()const;
    void setData(const int & value);
    nodeNumber * getNext()const;
    void setNext(nodeNumber * node);
    nodeMatrix * getRow()const;
    void setRow(nodeMatrix * node);
    friend  ostream & operator << (ostream & os , const nodeMatrix & n);
    nodeMatrix(/* args */);
    ~nodeMatrix();
};
ostream & operator << (ostream & os , const nodeMatrix & n){
     os << n.row ;
}
nodeMatrix::nodeMatrix(/* args */):row(0),next(0),down(0)
{
}

nodeMatrix::~nodeMatrix()
{
}
int nodeMatrix::getData()const{
    return row;
}
nodeMatrix * nodeMatrix::getRow()const{
    return down;
}
nodeNumber * nodeMatrix::getNext()const{
    return next;
}
void nodeMatrix::setData(const int & value){
    row = value;
}
void nodeMatrix::setRow(nodeMatrix * node){
    down = node;
}
void nodeMatrix::setNext(nodeNumber * node){
    next = node;
}
