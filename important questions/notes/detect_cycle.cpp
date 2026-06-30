//https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?track=DSASP-Graph&batchId=154class Solution {
 #include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
      bool dfs(int node,int parent,vector<int>&vis,vector<vector<int>>& adj){
          vis[node]=1;
          for(auto it:adj[node]){
              if(!vis[it]){
                 if (dfs(it,node,vis,adj))
                 return true;
              }
               else if(it!=parent){
                  return true;
              }
          }
          return false;
      }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj)==true)return true;
            }
        }
        return false;
    }
    
};

//you can see why we immendiately return the value when we fidn the ans in the dfs function
// because we are only intrested in knowing if there is a cycle or not so as soon as we find it we can return the value and stop the further execution of the code.