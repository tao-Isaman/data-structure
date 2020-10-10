#include "BinaryTree.h"
#include "BST.h"
#include <stdlib.h>
#include "ExpressionTree.h"
using namespace std;

void testBST(){
    BST<int>  tree;
    for (int i = 0; i < 10; i++)
    {
        int num = rand() % 20 + 1 ;
        printf("%d ",num);
        BinaryNode<int> * val = new BinaryNode<int>(num);
        tree.insert(val);
    }
    cout << endl;
    tree.inorder();
    cout << endl;
    tree.DisplayBST();


}

void testBinaryTree(){
    BinaryTree<int> * btree;

    BinaryNode<int> * n3 = new BinaryNode<int>(3,NULL,NULL);
    BinaryNode<int> * n5 = new BinaryNode<int>(5,NULL,NULL);
    BinaryNode<int> * n7 = new BinaryNode<int>(7,n5,NULL);
    BinaryNode<int> * n9 = new BinaryNode<int>(9,n7,NULL);
    BinaryNode<int> * n4 = new BinaryNode<int>(4,n3,n9);
    BinaryNode<int> * n17 = new BinaryNode<int>(17,NULL,NULL);
    BinaryNode<int> * n16 = new BinaryNode<int>(16,NULL,n17);
    BinaryNode<int> * n20 = new BinaryNode<int>(20,NULL,NULL);
    BinaryNode<int> * n18 = new BinaryNode<int>(18,n16,n20);
    BinaryNode<int> * n15 = new BinaryNode<int>(15,NULL,n18);
    BinaryNode<int> * n14 = new BinaryNode<int>(14,n4,n15);
    btree -> setRoot(n14);
    //btree -> BinaryDisplay();
    btree -> inorder();
    cout << endl;
    btree -> inorderWithStack();
    cout << endl;
    btree -> preorder();
    cout << endl;
    btree -> preorderWithStack();
    cout << endl;
    btree -> postorder();
    cout << endl;
    btree -> postorderWithStack();
    

}
void testEPT(){
    ExpressionTree<char>  ept;
    BinaryNode<char> * root = ept.buildFromPostfix("362+*");
    ept.setRoot(root);
   // ept.inorder();
    double check = ept.evaluate(root);
    cout << check << endl;
    

}

int main(){
    //5226*+24+1-
    //testBinaryTree();
    //testBST();
    testEPT();



    system("pause");
    return 0;
}