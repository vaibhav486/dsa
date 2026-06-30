#include <bits/stdc++.h>
using namespace std; 
class Solution {
  public:
      bool dfs(int node,vector<int>&vis,vector<int>&path,vector<vector<int>>& adj){
          vis[node]=1;
          path[node]=1;
          for(auto it:adj[node]){
              if(!vis[it]){
                 if (dfs(it,vis,path,adj)){
                        return true;}
              }
               else if(path[it]==1){
                  return true;
              }
          }
          path[node]=0;
          return false;
      }
    bool isCyclic(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
           // adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(V,0);
        vector<int>path(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,path,adj)==true)return true;
            }
        }
        return false;
    }
    
};