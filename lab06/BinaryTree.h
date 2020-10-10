#pragma once
#include <iostream>
#include "BinaryNode.h"
#include <stack>

using namespace std;

template<class T>
class BinaryTree;

/* template<class T>
std::ostream & operator << (std::ostream &,const BinaryTree<T> &); */

template<class T>
class BinaryTree
{
private:
   BinaryNode<T> * root = NULL ;
public:
    void setRoot(BinaryNode<T> * node);
    BinaryNode<T> * getRoot()const ;
    void BinaryDisplay();
    void inorder(BinaryNode<T> * node)const;
    void preorder(BinaryNode<T> * node)const;
    void postorder(BinaryNode<T> * node)const;
    void inorder()const;
    void preorder()const;
    void postorder()const;
    void inorderWithStack() const;
    void preorderWithStack() const;
    void postorderWithStack() const;
    bool isEmpty()const;
    bool isSame(BinaryTree<T> * t1 , BinaryTree<T> * t2);
    BinaryTree(/* args */);
    ~BinaryTree();
    //friend std::ostream & operator << <> (std::ostream & os,const BinaryTree<T> & bt);
};

/* template<class T>
std::ostream & operator << <> (std::ostream & os,const BinaryTree<T> & bt){
    os << "Root Node : ";
    os << bt.getRoot() -> getData();
    return os;
} */
template<class T>
bool BinaryTree<T>::isEmpty()const{
    
   // int a = root -> getData();
   // printf("WTF %d \n",a);
   
    
    return root == NULL;
}

template<class T>
void BinaryTree<T>::preorderWithStack() const{
    cout << "preorder with Stack : " ;
    
    stack <BinaryNode<T>*>  st;
    BinaryNode<T> * node = root;
    st.push(node);
     while(!st.empty()){

         node =st.top();
        cout << node -> getData() <<  " , " ;
        st.pop();
        if(node -> getRight() != NULL)
           st.push(node -> getRight());
        if(node -> getLeft() != NULL)
            st.push(node -> getLeft());
    }
    
    
}  

template<class T>
void BinaryTree<T>::postorderWithStack() const{
    cout << "postorder with Stack : " ;
    //cout << "check 1";
    stack <BinaryNode<T>*>  st1;
    stack <BinaryNode<T>*>  st2;
    BinaryNode<T> * node = root;
    st1.push(node);
    while(!st1.empty()){
      //  cout << "check 1";
        node = st1.top();
        st1.pop();
        st2.push(node);
        if(node -> getLeft() != NULL)
            st1.push(node -> getLeft());
        if(node -> getRight() != NULL)
            st1.push(node -> getRight());
    }
        while(!st2.empty()){
          //  cout << "check 2";
            node = st2.top();
            cout << node -> getData() << " , ";
            st2.pop();
        }
    


}  

template<class T>
void BinaryTree<T>::inorderWithStack() const{
    cout << "inorder with Stack : " ;
    
    stack <BinaryNode<T>*>  st;
    BinaryNode<T> * node = root;
    while (!st.empty() || node != NULL)
    {
        while(node != NULL){
            st.push(node);
            node = node -> getLeft();
        }
    
    if(!st.empty()){
        node = st.top();
        st.pop();
        cout << node -> getData() <<  " , " ;
        node = node ->getRight() ;
    }
    
    }
}  

template<class T>
bool BinaryTree<T>::isSame(BinaryTree<T> * t1 , BinaryTree<T> * t2){
    //เช็คว่า Tree 2 ต้นเหมือนกันไหม
    //ออกข้อสอบ 

}

template<class T>
void BinaryTree<T>::postorder(BinaryNode<T> * node)const{
    if(node != NULL){
        if(node -> getLeft() != NULL)
            inorder(node -> getLeft());
        if(node -> getRight() != NULL)
            inorder(node -> getRight());
        cout << node -> getData() << " , " ;    
    }
}

template<class T>
void BinaryTree<T>::preorder(BinaryNode<T> * node)const{
    if(node != NULL){
        cout << node -> getData() << " , " ;
        if(node -> getLeft() != NULL)
            inorder(node -> getLeft());
        if(node -> getRight() != NULL)
            inorder(node -> getRight());
    }
}

template<class T>
void BinaryTree<T>::inorder(BinaryNode<T> * node)const{
    if(node != NULL){
        if(node -> getLeft() != NULL)
            inorder(node -> getLeft());
        cout << node -> getData() << " , " ;
        if(node -> getRight() != NULL)
            inorder(node -> getRight());
    }
}

template<class T>
void BinaryTree<T>::BinaryDisplay(){
    cout << "Root Node : ";
    cout << getRoot() -> getData();
    
}



template<class T>
BinaryTree<T>::BinaryTree(/* args */)
{
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
}

template<class T>
void BinaryTree<T>::setRoot(BinaryNode<T> * node){
    root = node;
}

template<class T>
BinaryNode<T> * BinaryTree<T>::getRoot()const{
return root;
}

template<class T>
void BinaryTree<T>::inorder()const{
    cout << "inorder : ";
    BinaryNode<T> * node = root;
    inorder(node);
}

template<class T>
void BinaryTree<T>::preorder()const{
    cout << "preorder : ";
    BinaryNode<T> * node = root;
    preorder(node);
}

template<class T>
void BinaryTree<T>::postorder()const{
    cout << "postorder : ";
    BinaryNode<T> * node = root;
    postorder(node);
}