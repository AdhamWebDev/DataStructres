#include <iostream>
#include <exception>
using namespace std;
class Arraylist{
    int size;
    int capacity;
    int *arr;
    void expand(){
        capacity*=2;
        int *arr2;
        arr2=new int[capacity];
        for(int i=0;i<size;i++){
            arr2[i]=arr[i];
        }
        delete []arr;
        arr=arr2;
    }

public:
    Arraylist(){
        capacity=5;
        size=0;
        arr=new int[capacity];

    }


    void addToLast(int x){
        if(size==capacity){
            expand();
        }
        arr[size]=x;
        size++;
    }

    void deleteLast(){
        if(size!=0){
        size--;
        }else{
        cout<<"Empty array"<<endl;
        }
    }

    void addBeginning(int element){
        if(size==capacity){
            expand();
        }
        for(int i=size;i>0;i--){
            arr[i]=arr[i-1];

        }
        arr[0]=element;
        size++;
}

    void deleteFirst(){
        for(int i=0;i<size;i++){
            arr[i]=arr[i+1];
        }
            size--;
    }

    void updateElement(int index, int x){
        if(index>=0 && size!=0){
        arr[index]=x;
        }
    }


    bool search(int value){
        if(size==0) return false;
        for(int i=0;i<=size;i++){
            if(arr[i]==value)
                return true;
        }
        return false;
    }

    void addToIndex(int index,int element){
        if(size==capacity){
            expand();
        }
        for(int i=size;i>index;i--){
            arr[i]=arr[i-1];
        }
        arr[index]=element;
        size++;

    }

    void deleteByIndex(int index){
        for(int i=index;i<size-1;i++){
            arr[i]=arr[i+1];
        }
        size--;
    }
    void print(){
        for(int i=0;i<size;i++){

            cout<<arr[i]<<" ";
        }
    }

    void clear(){
    size=0;
    }

    int front(){
        return arr[0];
        }

    int back(){
        return arr[size-1];
        }

    void shrinkToFit(){
        capacity=size;
        int *temp=new int[capacity];
        for(int i=0;i<size;i++){
            temp[i]=arr[i];
            }
    delete []arr;
    arr=temp;
    }

    int& operator[](int index){
        if(index<=size && size!=0)
        return arr[index];
        else throw out_of_range("Index is out of range");
    }

};

int main()
{
    Arraylist mylist;
    mylist.addToLast(1);
    mylist.addToLast(2);
    mylist.addToLast(4);
    mylist.addToLast(5);
    mylist.print();
    cout<<endl;
    mylist.addToIndex(2,3);
    mylist.print();
    cout<<endl;
    mylist.deleteByIndex(2);
    mylist.print();
    cout<<endl;
    try{
    mylist[200]=8;
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
    mylist.print();
    cout<<endl;
}
