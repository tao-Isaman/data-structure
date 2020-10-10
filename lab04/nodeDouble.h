#pragma once
using namespace std;

class nodeDouble
{
private:
    int data;
    nodeDouble * next;
    nodeDouble * prev;

public:
    int getData()const;
    void setData(const int & value);
    nodeDouble * getNext()const;
    void setNext(nodeDouble * node);
    nodeDouble * getPrev()const;
    void setPrev(nodeDouble * node);
    friend  ostream & operator << (ostream & os , const nodeDouble & n);
    nodeDouble(/* args */);
    ~nodeDouble();
};
ostream & operator << (ostream & os , const nodeDouble & n){
    os << n.data ;
}

nodeDouble::nodeDouble(/* args */):data(0),next(0),prev(0)
{
}

nodeDouble::~nodeDouble()
{
}
int nodeDouble::getData()const{
return data;
}
nodeDouble * nodeDouble::getNext()const{
return next;
}
nodeDouble * nodeDouble::getPrev()const{
return prev;
}
void nodeDouble::setData(const int & value){
    data = value;
}
void nodeDouble::setNext(nodeDouble * node){
    next = node;
}
void nodeDouble::setPrev(nodeDouble * node){
    prev = node;
}