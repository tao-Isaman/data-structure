#pragma once
#include "BinaryTree.h"

template <class T>
class BST;

template <class T>
class BST : public BinaryTree<T>
{
private:
    /* data */
public:
    void DisplayBST();
    BinaryNode<T> * search(T key);
    BinaryNode<T> * search(BinaryNode<T> * node, T key);
    void insert(BinaryNode<T> * node);
    void insert(BinaryNode<T> * r, BinaryNode<T> * node);
    void remove(T data);
    void remove(BinaryNode<T> * parent ,BinaryNode<T> * node);
    BST(/* args */);
    ~BST();
};
template <class T>
void BST<T>::DisplayBST(){
    BinaryTree<T>::inorder();
}



template <class T>
void BST<T>::remove(T data){
    if(BinaryTree<T>::isEmpty())
    return;
    BinaryNode<T>* parent = NULL;
    BinaryNode<T>* node = BinaryNode<T>::getRoot();
    while(node != NULL && node -> getData() != data){
        parent = node;
        node = (data<node -> getData()) ? node -> getLeft():node -> getRight();
    }
    if(node == NULL)
    {
        cout << "Error 404 ";
        return;
    }
    else
         remove(parent,node);
}
template <class T>
void BST<T>::remove(BinaryNode<T> * parent ,BinaryNode<T> * node){
     //case 1
    if(isLeaf(node)){
        if(parent == NULL)
        BinaryTree<T>::setRoot(NULL);
        else{
            if(parent -> getLeft() == node)
                parent -> setLeft(NULL);
            else
                parent -> setRight(NULL); 
        }
    }
    //case 2
    else if (node ->  getLeft() == NULL || node -> getRight() == NULL){
        BinaryNode<T> *child = (node -> getLeft() != NULL) ? node -> getLeft() : node -> getRight() ;
        if(node == BinaryTree<T>::getRoot())
            setRoot(child);
        else{
            if(parent -> getLeft() == node)
                parent -> setLeft(child);
            else
                parent -> setRight(child);
        }
    }
    //case 3
    else {
        BinaryNode<T> * succp = node;
        BinaryNode<T> * succ = node -> getRight();
        while(succ ->  getLeft() != NULL) {
            succp = succ;
            succ = succ -> getLeft(); 
        }
        if(succp -> getLeft() = succ)
            succp -> setLeft(succ -> getRight());
        else 
            succp -> setRight(succ -> getRight());

        node -> setData(succ -> getData());

        node = succ;
    }
    delete node;
}



template <class T>
void BST<T>::insert(BinaryNode<T> * node){
   // printf("check 0 \n");
    if(node == NULL){
      //  printf("check 1 \n");
        return;
    }
    if(BinaryTree<T>::isEmpty()){
      //  printf("check 2 \n");
        BinaryTree<T>::setRoot(node);
    }
    else
    {
     //   printf("check 3 \n");
        insert(BinaryTree<T>::getRoot(),node);
    }
}
template <class T>
void BST<T>::insert(BinaryNode<T> * r,BinaryNode<T> * node){
    if(node -> getData() == r -> getData())
    return;
    else if(node -> getData() < r -> getData()) {
        if(r -> getLeft() == NULL)
            r -> setLeft(node);
        else
            insert(r -> getLeft(),node);
    }
    else{
        if(r -> getRight() == NULL)
            r -> setRight(node);
        else
            insert(r -> getRight(),node);
    } 


}





template <class T>
BST<T>::BST(/* args */)
{
}


template <class T>
BST<T>::~BST()
{
}

template <class T>
BinaryNode<T> * BST<T>::search(T key){
    BinaryNode<T> * node = search(BinaryTree<T>::getRoot(),key);
    if(node != NULL)
        cout << " Node : " << node -> getData() << endl;
    else
    {
        cout << " Key not found " << key << endl; 
    }
    return node;

}
template <class T>
BinaryNode<T> * BST<T>::search(BinaryNode<T> * node,T key){
    if(node == NULL) return NULL;
    if(key == node -> getData())
        return node;
    else if (key < node -> getData())
        return search(node -> getLeft(),key);
    else
    {
        return search(node -> getRight(),key);
    }
}