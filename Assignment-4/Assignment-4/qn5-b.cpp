#include <iostream>
#include <queue>
using namespace std;

class Stack{
  queue<int> q;
public:
  void push(int x){
    q.push(x);
    for(int i=0;i<q.size()-1;i++){
      q.push(q.front());
      q.pop();
    }
  }
  void pop() {
      if (q.empty()) {
        cout << "Stack is Empty\n";
      }
      q.pop();
    }

  void display(){
    if (q.empty()) {
      cout << "Stack is Empty\n";
    }else{
      int size = q.size();
      for(int i=0;i<size;i++){
        cout<<q.front()<<" ";
        q.pop();
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

