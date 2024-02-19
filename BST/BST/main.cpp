#include <iostream>
using namespace std;
class Node{
public:
    int value;
    Node *left;
    Node *right;

    Node(){
    value=0;
    this->left=nullptr;
    this->right=nullptr;
    }

    Node(int value){
      this->value=value;
      this->left=nullptr;
      this->right=nullptr;
  }

    Node(int value,Node *left,Node *right){
      this->value=value;
      this->left=left;
      this->right=right;
  }

 };

class BST{
    Node *root;
public:
    int size =0;

    BST(){
     root=nullptr;
    }
    bool search(int val){
        Node *p = root;
        while(p!=NULL){
            if(p->value==val) return true;
            if(val>p->value){
                p=p->right;
            }else{
            p=p->left;
            }
        }
        return false;
    }

    bool isEmpty(){
        return root==NULL;
    }

    void insert(int val){
        if(search(val)){
            return;
        }
        Node *n = new Node(val);
        size++;
        if(isEmpty()){
            root=n;
            return;
        }
        Node *p = root;
        Node *prev = nullptr;
        while(p!=nullptr){
        if(val>p->value){
            prev=p;
            p=p->right;
        }else{
            prev=p;
            p=p->left;
        }
            }
        if(val>prev->value){
            prev->right=n;
        }else{
            prev->left=n;
        }
    }

    int getMin(){
        Node *p = root;
        while(p->left!=NULL){
            p=p->left;
        }
        return p->value;
    }

    int getMax(){
        Node *p = root;
        while(p->right!=NULL){
            p=p->right;
        }
        return p->value;
    }


    void inOrder(Node *r){
        if(r==nullptr) return;
        inOrder(r->left);
        cout<<r->value<<" ";
        inOrder(r->right);
    }

    void preOrder(Node *r){
        if(r==nullptr) return;
        cout<<r->value<<" ";
        inOrder(r->left);
        inOrder(r->right);
    }

    void postOrder(Node *r){
        if(r==nullptr) return;
        inOrder(r->left);
        inOrder(r->right);
        cout<<r->value<<" ";
    }

    void print(){
        cout<<"In Order: ";
        inOrder(root);
        cout<<endl;
        cout<<"Pre Order: ";
        preOrder(root);
        cout<<endl;
        cout<<"Post Order: ";
        postOrder(root);
    }



 };

int main()
{
    BST myTree;
    myTree.insert(10);
    myTree.insert(5);
    myTree.insert(12);
    myTree.insert(11);
    myTree.insert(13);
    myTree.insert(14);
    cout<<myTree.search(11);
    cout<<endl;
    cout<<myTree.getMin();
    cout<<endl;
    cout<<myTree.getMax();
    cout<<endl;
    myTree.print();
    cout<<endl;

}
