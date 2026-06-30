#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
        
  
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int>ans;
        int v=adj.size();
        vector<int>vis(v,0);
        vis[0]=1;
       
       
        
        queue<int>qu;
        qu.push(0);
        while(!qu.empty()){
            int node=qu.front();
            qu.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                if(!vis[it]){
                qu.push(it);
                vis[it]=1;}
            }
        }
        return ans;
        
    }
};