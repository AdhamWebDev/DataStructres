#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};

class Linklist{
public:
    Node *head=NULL;
    Node *tail=NULL;
    //add to the end of the linkedlist
    void addToLast(int x){
        Node *n = new Node;
        n->data = x;
        n->next = NULL;
        //empty
        if(head==NULL){
            head=n;
            tail=n;
        }else{
            //add using tail
            //tail->next=n;
            //tail=n;

            //add without tail
            Node *p=head;
            while(p->next!=NULL){
                p=p->next;
            }
            p->next=n;

        }
    }

    void print(){
        if(head==NULL){
            cout<<"Linkedlist is empty"<<endl;
        }else{
        Node *p=head;
        while(p!=NULL){
            cout<<p->data<<" ";
              p=p->next;
        }
        cout<<endl;
        cout<<"--------------------";
        }
    }

    bool isEmpty(){
       return head==NULL;
    }

    void addToBeginning(int x){
        Node *n = new Node;
        n->data = x;
        n->next = NULL;
        if(isEmpty()){
            head=n;
            tail=n;
        }else{
            n->next=head;
            head=n;
        }
    }

    void deleteFromBeginning(){
        Node *p = head;
        head=head->next;
        delete p;
    }

    void deleteFromEnd(){
      Node *target = head;
      Node *ptr = NULL;
      while(target->next!=NULL){
        ptr=target;
        target=target->next;
      }
      ptr->next=NULL;
      delete target;
    }

      void deleteFromEndUsingTail(){
        Node *target = tail;
        Node *ptr = head;
        while(ptr->next!=target){
            ptr=ptr->next;
        }
        ptr->next=NULL;
        tail=ptr;
        delete target;
    }

    Node * search(int x){
        Node *p = head;
        Node *target = NULL;
        while(p!=NULL){
            if(p->data==x){
                target=p;
                break;
            }
            p=p->next;
        }
            return target;
    }

    void addAfterElement(int e, int x){
        Node *n = new Node;
        n->data=x;
        n->next=NULL;

        Node *p = head;
        Node *target = NULL;
        while(p!=NULL){
            if(p->data==e){
                target=p->next;
                n->next=target;
                p->next=n;
                break;

            }else{
            p=p->next;
            }
        }
    }

    void addBeforeElement(int e,int x){
        Node *n = new Node;
        n->data=x;
        n->next=NULL;

        Node *p = head;
        Node *target = NULL;
        while(p!=NULL){
            if(p->data==e){
                n->next=p;
                target->next=n;
                break;

            }else{
                target=p;
                p=p->next;
            }
        }
    }

    void deleteElement(int x){
        Node *t = head;
        Node *p = NULL;
        while(t->data!=x){
            p=t;
            t=t->next;
        }
        p->next=t->next;
        delete t;
    }

    void deleteLinkedlist(){
        Node *p = head;
        while(p!=NULL){
          Node *temp = p->next;
          delete p;
          p=temp;
        }
        head=p;
    }
// **************************************************************
    void swapTwoElements(int x,int y){
    Node *p = head;
    Node *t = NULL;
    Node *temp = NULL;
    while(p->data!=x){
            temp=p;
            p=p->next;

    }
            t=p->next;
            temp->next=t;
            p->next=t->next;
            t->next=p;

    }

    void test(){
        cout<<head->next->next->next->data;
    }

    void reverseLinkedlist(){
        Node *p = head;
        Node *t = NULL;
        while(p!=NULL){
            if(p->next!=NULL){
                t=p;
                p=p->next;
            }
            p->next=head;

        }
    }

    void reverseList(Node *p){
        if(p==NULL) return;
        reverseList(p->next);
        cout<<p->data<<" ";

    }

};



int main()
{
    Linklist myList;
    myList.addToLast(1);
    myList.addToLast(2);
    myList.addToLast(3);
    myList.addToLast(4);
    myList.addToLast(5);
    myList.print();
    myList.reverseList()
    cout<<"============";
    myList.addToLast(1);
    myList.print();
    myList.addToLast(3);
    myList.print();
    myList.addToLast(5);
    myList.print();
    myList.addToLast(9);
    myList.print();
    myList.addToLast(7);
    myList.print();
    cout<<myList.search(2);
    myList.addBeforeElement(9,4);
    myList.print();
    myList.deleteElement(9);
    myList.print();
    myList.swapTwoElements(3,5);
    myList.print();
    myList.test();
}
