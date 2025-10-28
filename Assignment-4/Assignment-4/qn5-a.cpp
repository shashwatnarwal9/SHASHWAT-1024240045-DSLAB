#include <iostream>
#include <queue>
using namespace std;

class Stack{
  queue<int> q1,q2;
public:
  void push(int x){
    if(q1.empty()){
      q1.push(x);
    }else{
      int size = q1.size();
      for(int i =0;i<size;i++){
        q2.push(q1.front());
        q1.pop();
      }
      q1.push(x);
      for(int j=0;j<size;j++){
        q1.push(q2.front());
        q2.pop();
      }
    }
  }
  void pop() {
      if (q1.empty()) {
        cout << "Stack is Empty\n";
      }
      q1.pop();
    }

  void display(){
    if (q1.empty()) {
      cout << "Stack is Empty\n";
    }else{
      int size = q1.size();
      for(int i=0;i<size;i++){
        cout<<q1.front()<<" ";
        q1.pop();
      }
    }
    
  }
};

int main()
{
  Stack s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.display();
  return 0;
}

