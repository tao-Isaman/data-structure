#pragma once
#include "nodeMatrix.h"

class Matrix
{
private:
    nodeMatrix * rowPtr;
    nodeMatrix * lastRowPtr;
    nodeNumber * columPtr;
    nodeNumber * lastColumPtr;
    //int rSize , cSize;
    bool isEmpty()const;
    
    /* data */
public:
    
    void buildMatrix(int a[][7],int rSize, int cSize);
    bool checkRowZero(int a[],int size);
    nodeMatrix * getNode(const int & value)const;
    bool isRowEmpty()const;
    void buildRow(int rowNum ,int row[],int size);
    friend ostream & operator << (ostream & os, const Matrix & m);
    Matrix(/* args */);
    ~Matrix();
};
ostream & operator << (ostream & os, const Matrix & m){
    nodeMatrix * checkRPt = m.rowPtr;
    nodeNumber * checkPt = checkRPt -> getNext();
    
    while(checkRPt != 0){
    checkPt = checkRPt -> getNext();
        while (checkPt != 0)
        {
            os << checkPt -> getData() << " " ;
            checkPt = checkPt -> getNext();
        }
    os << "\n" ;
    checkRPt = checkRPt -> getRow();
    }
    os << endl ;
}
   

Matrix::Matrix(/* args */):rowPtr(0),lastRowPtr(0),columPtr(0),lastColumPtr(0)
{
}

Matrix::~Matrix()
{
}
bool Matrix::isEmpty()const{return rowPtr == NULL;}
bool Matrix::isRowEmpty()const{return columPtr == NULL;}

void Matrix::buildRow(int rowNum ,int row[],int size){
    //rowPtr = lastRowPtr = 0;
    columPtr = lastColumPtr = 0;
    nodeMatrix * cRow = new nodeMatrix();
    cRow -> setData(rowNum);
    for(int i = 0; i < size ; i++){
        nodeNumber * sRow = new nodeNumber();
        sRow -> setData(row[i]);
        sRow -> setColum(i);
        if(isRowEmpty()){
            columPtr = lastColumPtr = sRow ;
        }
        else if(row[i] != 0){
            lastColumPtr -> setNext(sRow);
            lastColumPtr = sRow ;
        }

    }
    cRow -> setNext(columPtr);
    if(isEmpty()){
        rowPtr = lastRowPtr = cRow;
    }
    else if(!checkRowZero(row,size)){
        lastRowPtr -> setRow(cRow);
        lastRowPtr = cRow ;
    }
}
nodeMatrix * Matrix::getNode(const int & value)const{

}
bool Matrix::checkRowZero(int a[],int size){
    bool check = true;
    int i = 0;
    while(i < size){
        if(a[i] != 0)
            check = false;
        i++;
    }
    return check ;
}
void Matrix::buildMatrix(int a[][7],int rSize , int cSize){
    for(int i = 0; i < rSize ; i++){
        buildRow(i,a[i],cSize);
    }
}


