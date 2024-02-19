#include <iostream>
using namespace std;
class Node{
public:
	int data;
	Node *next;
};
class Queue{
public:
	Node *Front=nullptr;
	Node *Back=nullptr;
	bool isEmpty(){
    	if(Front==nullptr) return true;
    	else return false;
	}
	// Enqueue
	void push(int x){
    	Node *n=new Node;
    	n->data=x;
    	n->next=nullptr;
    	if(isEmpty()){
        	Front=n;
        	Back=n;
    	}
    	else{
        	Back->next=n;
        	Back=n;
    	}
	}
	// Dequeue
	void pop(){
    	if(isEmpty()) cout<<"empty"<<endl;
    	else if(Front==Back){
        	Node *p=Front;
        	Front=Back=nullptr;
        	delete p;
    	}
    	else{
        	Node *p=Front;
        	Front=Front->next;
        	delete p;
    	}
	}
	// front
	int front(){
    	return Front->data;
	}
	int back(){
    	return Back->data;
	}
};
int main()
{
	Queue q;
	q.push(10);
	cout<<q.front()<<" "<<q.back()<<endl; // 10 10
	q.push(20);
	cout<<q.front()<<" "<<q.back()<<endl; // 10 20
	q.push(30);
	cout<<q.front()<<" "<<q.back()<<endl; // 10 30
	q.pop();
	cout<<q.front()<<" "<<q.back()<<endl; // 20 30

}
