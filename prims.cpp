#include <iostream> 
using namespace std;
#include<bits/stdc++.h>

class Compare
{
public:
    bool operator()(tuple<int,int,int>& a, tuple<int,int,int>& b)
    {
        return get<0>(a) > get<0>(b);
    }
};

int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,Compare> pq;
        
        pq.push(make_tuple(0,0,-1));
        
        unordered_map<int,bool> vis;
        
        int wt=0;
        
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            
            if (vis[get<1>(t)]) {
                continue; // Skip this node if already visited
            }
            
            vis[get<1>(t)]=true;
            
            wt+=get<0>(t);
            
            for(auto edge:adj[get<1>(t)]){
                int node=edge[0];
                int eWt=edge[1];
                int par=get<1>(t);
                
                if(!vis[node]){
                    pq.push(make_tuple(eWt,node,par));
                }
                
            }
            
        }
        
        return wt;
    }
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
    	cout << spanningTree(V, adj) << "\n";
    }

    return 0;
}
