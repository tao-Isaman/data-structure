#include <iostream>
#include "linkList.h"
#include "linkStack.h"
#include "doubleLinklist.h"
#include "Matrix.h"
using namespace std;

void testMatrix(){
   Matrix m;
   int b[][7] = { {1,8,5,9,0,0,6},
                 {2,8,5,9,7,5,6},
                 {0,0,0,0,0,0,0},
                 {9,8,0,0,0,0,2} };
   m.buildMatrix(b,4,7);

   cout << m << endl;
}
void testStack(){
    linkStack st;
    st.push(5);
    st.push(8);
    cout << st ;
}
void testLinkList(){
    linkList list;
    list.insertAtFront(5);
    list.insertAtFront(9);
    list.insertAtBack(7);
    list.removeAtFront();
    
    cout << "The number of elements in the list " << list.getSize() << endl;
    cout << list;
}
void testDoubleLinkList(){
    doubleLinklist dl;
    dl.insertAtFront(1);
    dl.insertAtFront(2);
    dl.insertAtBack(9);

    cout << "The number of elements in the list " << dl.getSize() << endl;
    cout << dl;

}

int main(){
//testLinkList();
//testStack();
//testDoubleLinkList();
testMatrix();

system("pause");
return 0;
}