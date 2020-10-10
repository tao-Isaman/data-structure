#pragma once
using namespace std;

class nodeNumber
{
private:
    int colum;
    int data;
    nodeNumber * next;
    /* data */
public:
    int getData()const;
    void setData(const int & value);
    nodeNumber * getNext()const;
    void setNext(nodeNumber * node);
    int getColum()const;
    void setColum(const int & node);
    friend  ostream & operator << (ostream & os , const nodeNumber & n);
    nodeNumber(/* args */);
    ~nodeNumber();
};
ostream & operator << (ostream & os , const nodeNumber & n){
    os << n.data ;
}

nodeNumber::nodeNumber(/* args */):colum(0),data(0),next(0)
{
}

nodeNumber::~nodeNumber()
{
}
int nodeNumber::getColum()const{
    return colum;
}
int nodeNumber::getData()const{
    return data;
}
nodeNumber * nodeNumber::getNext()const{
    return next;
}
void nodeNumber::setColum(const int & value){
    colum = value;
}
void nodeNumber::setData(const int & value){
    data = value;
}
void nodeNumber::setNext(nodeNumber * node){
    next = node;
}

