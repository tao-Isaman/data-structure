#pragma once
#include <iostream>
using namespace std;


class node
{
private:
    int data;
    node* link;
public:
    int getData() const;
    node* getLink() const;
    void setData(const int & value);
    void setLink( node*  next);
    friend  ostream & operator << (ostream & os , const node & n);

    node(/* args */);
    ~node();
};
ostream & operator << (ostream & os , const node & n){
    os << n.data ;
}
node::node(/* args */):data(0), link(0)
{
}

node::~node()
{
}
int node::getData() const {return data;}
node* node::getLink() const{return link;}
void node::setData(const int & value){ data = value;}
void node::setLink(node*  next){link = next;}