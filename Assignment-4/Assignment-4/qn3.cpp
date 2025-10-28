#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q1;
    q1.push(4);
    q1.push(7);
    q1.push(11);
    q1.push(20);
    q1.push(5);
    q1.push(9);
    int size = q1.size();
    if(size%2==0){
      int n=size/2;
      queue<int>x,y;
      for(int i=0;i<n;i++){
        x.push(q1.front());
        q1.pop();
      }
      for(int i=0;i<n;i++){
        cout<<x.front()<<" ";
        x.pop();
        cout<<q1.front()<<" ";
        q1.pop();
      }
    }
    return 0;
}
