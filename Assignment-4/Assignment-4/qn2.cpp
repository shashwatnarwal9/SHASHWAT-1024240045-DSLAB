#include <iostream>
#include <vector>
#define MAX 4
using namespace std;

class Queue{
public:
  int arr[MAX];
  int f=-1,r=-1;

  void enqueue(int val){
    if(isFull()){
      cout<<"Cant Perform enqueue operation, queue is Full";
    }else{
      if(f==-1){
        f=r=0;
      }else{
        r=(r+1)%MAX;
      }
      arr[r]=val;
      
    }
    
  }
  int dequeue(){
    if(isEmpty()){
      return -1;
    }else{
      int y = arr[f];
      if (f == r) {
        f = r = -1;
      } else {
        f = (f + 1) % MAX;
      }
      return y;
    }
    
  }
  bool isEmpty(){
    if(f==-1){
      return true;
    }else{
      return false;
    }
  }
  bool isFull(){
    if(f==(r+1)%MAX){
      return true;
    }else{
      return false;
    }
  }
  void display(){
    if(isEmpty()){
        cout<<"Queue is empty\n";
    } else {
        int i = f;
        while(true){
            cout<<arr[i]<<" ";
            if(i == r) break;
            i = (i+1) % MAX;
        }
        cout<<endl;
    }
  }

  void peek(){
    if(isEmpty()){
      cout<<"Queue is empty\n";
    }else{
      cout<<arr[f]<<endl;
    }
  }
};




int main(){
  Queue q1;
  int x =0;
  while(x!=1){
    int exp;
    cout<<"MENU\n"
      <<"1- to enqueue\n"
      <<"2- to dequeue\n"
      <<"3- to check if queue is empty\n"
      <<"4- to check if queue is full\n"
      <<"5- to display all elements\n"
      <<"6- to check peek value\n"
      <<"7- Exit\n";
    cin>>exp;
    switch (exp)
    {
      case 1:{
        int p;
        cout<<"Enter element\n";
        cin>>p;
        q1.enqueue(p);
        break;
      }
        
      case 2:{
        int t = q1.dequeue();
        if(t==-1){
          cout<<"Cant Perform dequeue operation, queue is empty";
        }else{
          cout<<t<<endl;
        }
        break;
      }
        
      case 3:{
        if(q1.isEmpty()){
          cout<<"it is empty\n";
        }else{
          cout<<"it is not empty\n";
        }
        break;
      }
        
      case 4:{
        if(q1.isFull()){
          cout<<"it is full\n";
        }else{
          cout<<"it is not full\n";
        }
        break;
      }
        
      case 5:{
        q1.display();
        break;
      }
        
      case 6:{
        q1.peek();
        break;
      }
        
      case 7:{
        cout<<"Exiting the program\n";
        return 0;
      }
        
      default:{
        cout<<"Enter valid value\n";
        break;
      }
        
    }
  }
  
  return 0;
}