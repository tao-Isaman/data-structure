#pragma once
#include "linklist.h"
#include "line.h"
#include <string.h>
#include <ostream>
#include <fstream>

using namespace std;

class textEditor
{
private:
    linklist<line> list;
    /* data */
public:
    void saveFile(string fname);
    void readFile(string fname);
    void deleteLine();
    void insertLine();
    //friend ostream & operator << (ostream & os , const textEditor & te);
    textEditor(/* args */);
    ~textEditor();
 };
 /*
ostream & operator << (ostream & os , const textEditor & te){
    os << te.list ;
    return os;

} */

textEditor::textEditor(/* args */)
{
}

textEditor::~textEditor()
{
}

/* void textEditor::readFile(string fname){
    list.clear();
    ifstream fin(fname,ios::in);

    if(!fin){
        cerr << "Error in reading File";
        exit(1);
    }
    string str;
    while (getline(fin,str))
    {
       cout << str << endl;
       line line(str);
       list.insertAtBack(line);
    }
    fin.close();
}

void textEditor::saveFile(string fname){
    ofstream fout(fname,ios::out);

    if(!fout){
        cerr << "Error in opening File";
        exit(1);
    }
    string str;
    Node<line> * currPtr = list.getHeadPtr();
    while (currPtr != NULL){
        str = currPtr -> getData().getData();
        currPtr = currPtr -> getLink();
        fout << str + "Wn" ;
    }
    fout.close();
} */

void textEditor::insertLine(){
    char str[200];
    cout << "Enter data for line : ";
    cin.getline(str,200);
    line line(str);
    list.insertAtBack(line);
    list.linkDisplay() ;

}
void textEditor::deleteLine(){
    int pos;
    cout << "enter the line # " ;
    cin >> pos;
    list.removeAt(pos);
    list.linkDisplay();



}




