#pragma once
#include "BinaryTree.h"
#include <stack>
#include <stdio.h>

#include <conio.h>
#include <cstdlib>
#include <string.h>

using namespace std;




template <class T>
class ExpressionTree : public BinaryTree<char> 
{
private:
    bool isOperator(char c)const;
    /* data */
public:
    BinaryNode<char> * buildFromPostfix(string postfix);
    ExpressionTree(/* args */);
    double evaluate()const;
    double evaluate(BinaryNode<char> * node)const;
    ~ExpressionTree();
};


template <class T>
ExpressionTree<T>::ExpressionTree(/* args */) :BinaryTree<char>::BinaryTree()
{
}

template <class T>
ExpressionTree<T>::~ExpressionTree()
{
}

template <class T>
BinaryNode<char> * ExpressionTree<T>::buildFromPostfix(string postfix){
    stack<BinaryNode<char>*> st;
    BinaryNode<char> * t1 = new BinaryNode<char>() ;
    BinaryNode<char> * t2 = new BinaryNode<char>() ;

    for(int i = 0; i < postfix.length(); i ++){
       // cout << i;
        if(!isOperator(postfix[i])){
            BinaryNode<char> * t = new BinaryNode<char>();
            t -> setData(postfix[i]);
            st.push(t);

        }
        else {
            BinaryNode<char> * t = new BinaryNode<char>();
            t -> setData(postfix[i]);
            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();

            t -> setLeft(t1);
            t -> setRight(t2);
            st.push(t);

        }
    }
    BinaryNode<char> * rt = new BinaryNode<char>();
    rt = st.top();
    st.pop();
    return rt;
}

template <class T>
bool ExpressionTree<T>::isOperator(char c)const{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c =='^')
    return true;
    return false;
}

template <class T>
double ExpressionTree<T>::evaluate()const{
    printf("check 01 \n");
    char test = getRoot() ->getData();
    printf("%c " , test);
     return evaluate(getRoot()); 
}

template <class T>
double ExpressionTree<T>::evaluate(BinaryNode<char> * node)const{

   

    if(!isOperator(node -> getData()))
        return double((node -> getData()) - 48);

    if(node == NULL)
        return 0;
    double l_val = evaluate(node -> getLeft());
    double r_val = evaluate(node -> getRight());
    
    if (node->getData() == '+')  
        {  // printf("check + %d \n",l_val+r_val);
            return l_val+r_val;  
        
        }
  
    if (node -> getData() == '-')  
        {//printf("check - %d\n",l_val-r_val);
        return l_val-r_val;
        }  
  
    if (node -> getData() == '*')  
        {//printf("check * %d\n",l_val*r_val);
        return l_val*r_val;
        }  
  
    return l_val/r_val; 


}







