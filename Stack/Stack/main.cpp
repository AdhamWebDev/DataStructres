#include <iostream>
using namespace std;
class Node{
public:
	int data;
	Node *next;
};
class Stack{
public:
	Node *top=nullptr;
	int size=0;
	void push(int x){
   	Node *n=new Node;
   	n->data=x;
   	n->next=nullptr;
   	if(top==nullptr){
      	top=n;
      	size++;
   	}
   	else{
     	n->next=top;
     	top=n;
     	size++;
   	}
	}
	bool isEmpty(){
    	return top==nullptr;
	}
	int Size(){
    	return size;
	}
	int Top(){
    	return top->data;
	}
	void pop(){
    	if(top==nullptr){
        	cout<<"empty"<<endl;
    	}
    	else{
        	Node *p=top;
        	top=top->next;
        	delete p;
        	size--;
    	}
	}
};
int main()
{
   Stack s;
   s.push(2);
   s.push(5);
   s.push(7);
   while(!s.isEmpty()){
  	cout<<s.Top()<<" ";
  	s.pop();
   }
}
