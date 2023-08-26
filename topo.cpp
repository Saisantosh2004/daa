
#include <bits/stdc++.h>
using namespace std;

class Graph 
{
    private:
    void dfs(int node,int vis[], stack<int> &st, vector<int>adj[]){
      vis[node]=1;
      for(auto it:adj[node]){
          if(!vis[it]) dfs(it,vis,st,adj);
      }  
      
      st.push(node);
    }
    public:
    vector<int> topoSort(int v, vector<int> adj[]){
      int vis[v];
      for (int i = 0; i < v; i++)
        vis[i] = 0;
      
      stack<int> st;
      for(int i=0;i<v;i++){
          if(!vis[i]) dfs(i,vis,st,adj);
      }
      vector<int>ans;
      while(!st.empty()){
          ans.push_back(st.top());
          st.pop();
        }
      return ans;
  }
};

int main()
{
    int N,E;
    cout<<"enter number of vertices and edges:";
    cin>>N>>E;
    int u,v;
    
    vector<int> adj[N];

    cout<<"enter edges with direction (1 2 implies 1->2):";
    for(int i=0;i<E;i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    Graph obj;
    vector<int> res = obj.topoSort(N,adj); 

    for(auto x:res){
        cout<<x<<" ";
    }

    return 0;
}
