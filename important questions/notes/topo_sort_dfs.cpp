// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution {
     private:
         void topo(int node,vector<int>&vis,stack<int>&st,vector<vector<pair<int,int>>>&adj){
             vis[node]=1;
             for(auto &x:adj[node]){
                 int v=x.first;
                 if(!vis[v]){
                     topo(v,vis,st,adj);
                 }
             }
             st.push(node);
             
         }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
          vector<vector<pair<int,int>>>adj(V);
        vector<int>vis(V,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topo(i,vis,st,adj);
            }
        }
        vector<int>dist(V,INT_MAX);
       
        dist[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(dist[node]!=INT_MAX){
            for(auto &x:adj[node]){
                int v=x.first;
                int wt=x.second;
                if(dist[node]+wt<dist[v]){
                    dist[v]=dist[node]+wt;
                }
            }
            }
            
            
        }
        for(int i = 0; i < V; i++) {
    if(dist[i] == INT_MAX) {
        dist[i] = -1;
    }
}
        return dist;
    }
};
