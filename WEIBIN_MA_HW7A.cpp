/*
 * Author: weibin Ma
 * Title: hw7A
 * Date: 13/11/2019
 *
 */

#include <iostream>
#include "intrin.h"
using namespace std;
class LinkedList2 {
private:
    class Node{ // LinkedList2::Node
    public:
        int val;
        Node* next;
        Node(int data,Node *n):val(data),next(n){}
    };
    Node* head;
    Node* tail;
public:
    LinkedList2():head(nullptr),tail(nullptr){}

    ~LinkedList2(){
        Node* q;
        for(Node* p = head;p != nullptr;p = q){
            q = p ->next;
            delete p;
        }
        delete tail;
    }

    LinkedList2(const LinkedList2& orig){
        head = orig.head;
        tail = orig.tail;
        if(orig.head == nullptr){
            head = nullptr;
            return;
        }
        head = new Node(orig.head->val, nullptr);
        Node* p = orig.head->next;
        if (p == nullptr)
            return;
        // there are at least 2 nodes
        Node* q = head;
        for (; p != nullptr; p = p->next, q = q->next)
            q->next = new Node(p->val, nullptr);

    }
    LinkedList2& operator =(const LinkedList2& orig){
        Node* q;
        delete tail;
        for(Node* p = head;p != nullptr;p = q){
            q = p ->next;
            delete p;
        }
        if(&orig==this)return *this;
        LinkedList2 v(orig);
        if(head != NULL){
            Node *p = head;
            head = head->next;
            delete p;
        }
        head = v.head;
        tail = v.tail;
        v.tail = nullptr;
        v.head = nullptr;
        return *this;

    }
    // move constructor
    LinkedList2(LinkedList2&& orig) { // steal orig data while it's dying (nice)
        this->head = orig.head;
        this->tail = orig.tail;
        orig.head = nullptr;
        orig.tail = nullptr;
    }
    void addStart(int v){
        Node*p = new Node(v, nullptr);
        if(head == nullptr){
            head=p;
            tail=p;
        }else{
            p->next=head;
            head=p;
        }
    }
    void addEnd(int v){
        Node *p = new Node(v, nullptr);
        if(head== nullptr)
        {
            head=tail=p;
        }
        else
        {
            tail->next=p;
            tail=p;
        }
    }
    void removeStart(){
        if(head== nullptr)
        {
            cout<<"empty linklist, cannot be delete"<<endl;
            return;
        }
        else
        {
            Node *p=head;
            head=p->next;
            delete p;
            p = nullptr;
        }
    }
    void removeEnd(){
        if(head== nullptr)
        {
            cout<<"empty linklist, cannot be delete"<<endl;
            return;
        }
        else
        {
            Node *p=head;
            while(p->next!=tail)
            {
                p=p->next;
            }
            delete tail;
            tail=p;
            tail->next= nullptr;
        }

    }
    friend ostream& operator <<(ostream& s, const LinkedList2& list) {

        for (Node*p = list.head; p != nullptr; p = p->next)
                s << p->val << ",  ";

        return s;
    }
};
/**
  head --> nullptr

  head --> [ val=3 next= nullptr  ]

  head -->  [val=1 next= ---->  [ val=3 next= nullptr  ]



 */
int main() {
    LinkedList2 a;
    a.addStart(3); // 3 is the first element in the list
    a.addStart(1); // 1 3
    a.addStart(4); // 4 1 3
    for (int i = 1; i <= 5; i++)
        a.addEnd(i);
    a.removeStart();
    a.removeEnd();
    cout << a << '\n'; // print out the list, separated by spaces or commas

    LinkedList2 b = a;
    cout << b << '\n';

    LinkedList2 c;
    c.addStart(5);
    //cout << c << '\n';//for testing
    c = b; // wipe out c, copy in b
    cout << c << '\n';
}