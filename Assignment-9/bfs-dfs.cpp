#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int Val){
        V=Val;
        l=new list<int>[V];
    }

    void addEdge(int u,int v){
        l[u].push_back(v); 
        l[v].push_back(u); 
    }

    void printGraph(){
        for(int i=0;i<V;i++){
            cout<<i<<" : ";

            for(int neigh: l[i]){
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
        
    }

    void bfs(){
        vector<bool>vis(V,false);
        queue<int>q;
        q.push(0);
        vis[0]=true;
        while(q.size()>0){
            int u = q.front();
            q.pop();
            cout<<u<<" ";
            for(int val: l[u]){
                if(!vis[val]){
                    vis[val]=true;
                    q.push(val);
                }
            }
            
        }
        cout<<endl;
    }

    void dfsHelper(int u, vector<bool>&vis){
        cout<<u<<" ";
        vis[u]=true;

        for(int v: l[u]){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
        

    }

    void dfs(){
        int u = 0;
        vector<bool> vis(V,false);
        dfsHelper(u,vis);
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    // g.addEdge(2,3);
    g.addEdge(2,4);
    g.bfs();
    g.dfs();
    // g.printGraph();
    return 0;
}