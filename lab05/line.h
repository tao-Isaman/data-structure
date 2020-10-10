#pragma once
#include <iostream>
#include <string>

using namespace std;

class line
{
private:
    /* data */
    string data;
public:
   
    string getData() const;
    void setData(string  s);
    void lineDisplay();
    
    

    line(string s ="");
    ~line();
};

void  line::lineDisplay(){
    cout << getData();
}
/* ostream & operator << (ostream & os, const line & line){
    os << line.getData() ;
    return os;
} */

line::line(string s):data(s)
{
}

line::~line()
{
}
string line::getData()const{return data;}
void line::setData( string  s){data = s;}