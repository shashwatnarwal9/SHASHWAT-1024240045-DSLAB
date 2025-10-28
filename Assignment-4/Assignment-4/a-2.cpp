#include <iostream>
#include <queue>
using namespace std;
class SortValue
  {
    queue<int> q;
  public:
    void push(int x){
      if(q.empty()){
        q.push(x);
      }else{
        if(x<q.front()){
          q.push(x);
          for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
          }
        }else{
          q.push(x);
        }
      }
    }
    void pop() {
      if (q.empty()) {
        cout << "Queue is Empty\n";
      }
      q.pop();
    }
    void display(){
    if (q.empty()) {
      cout << "Queue is Empty\n";
    }else{
      int size = q.size();
      for(int i=0;i<size;i++){
        cout<<q.front()<<" ";
        q.pop();
      }
    }
    
  }
  
  };

int main() {
  

  SortValue abc;
  abc.push(11);
  abc.push(5);
  abc.push(4);
  abc.push(21);
  abc.display();
  return 0;
}