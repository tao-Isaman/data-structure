#include "line.h"
#include "Node.h"
#include "linklist.h"
#include "linkStack.h"
#include "linkQueue.h"
#include "nodeDouble.h"
#include "doubleLinklist.h"
//#include "textEditor.h"
#include <string>

using namespace std;

void testDouble(){
    nodeDouble<int> node(5);
    nodeDouble<char> node2('T');
    nodeDouble<string> node3("isaman ");

    doubleLinklist<int> list;
    list.insertAtBack(5);
    list.insertAtBack(5);
    list.insertAtBack(5);

    doubleLinklist<char> list1;
    list1.insertAtBack('t');
    list1.insertAtBack('a');
    list1.insertAtBack('o');

    doubleLinklist<string> list2;
    list2.insertAtBack("isaman ");
    list2.insertAtBack("isaman ");
    list2.insertAtBack("isaman ");

    list.linkDisplay();
    list1.linkDisplay();
    list2.linkDisplay();
    

    node.nodeDoubleDisplay();
    node2.nodeDoubleDisplay();
    node3.nodeDoubleDisplay();

}
void testLinklist(){
    linklist<int> list;
    list.insertAtFront(5);
    list.insertAtFront(6);
    list.insertAtFront(8);
    list.linkDisplay();

    linklist<char> list2;
    list2.insertAtFront('A');
    list2.insertAtFront('B');
    list2.insertAtFront('D');
    list2.linkDisplay();

    linklist<string> list3;
    list3.insertAtFront("BNK");
    list3.insertAtFront("48");
    list3.insertAtFront("Satchan");
    list3.linkDisplay();


}
void testQueue(){
    linkQueue<int> queue1;
    queue1.enqueue(3);
    queue1.enqueue(3);
    queue1.enqueue(3);

    linkQueue<char> queue2;
    queue2.enqueue('A');
    queue2.enqueue('A');
    queue2.enqueue('A');

    linkQueue<string> queue3;
    queue3.enqueue("Kak ");
    queue3.enqueue("Kak ");
    queue3.enqueue("Kak ");

    queue1.QueueDisplay();
    queue2.QueueDisplay();
    queue3.QueueDisplay();


}
void testStack(){
    linkStack<int> stack1;
    stack1.push(9);
    stack1.push(8);
    stack1.push(7);

    linkStack<char> stack2;
    stack2.push('A');
    stack2.push('D');
    stack2.push('C');

    linkStack<string> stack3;
    stack3.push("Isaman ");
    stack3.push("Isaman ");
    stack3.push("Isaman ");

    stack1.displayStack();
    stack2.displayStack();
    stack3.displayStack();


}
void testTextEditor(){
   // textEditor text;
   // text.insertLine();

    //  ยังไม่เสร็จนะ 
    //กลับไปทำต่อ

}

void testNode(){
    Node<int> n1(5);
    Node<char> n2('S');
    Node<string> n3("tetetet");

    n1.display();
    n2.display();
    n3.display();


}
void testLine(){

   line line;
   line.setData("test 01"); 
   line.lineDisplay();

}
int main(){
   // testNode();
   //testLinklist();
 // testStack();
  //testQueue();
  testDouble();
 // testLine();


    system("pause");
    return 0;
}