
//https://www.geeksforgeeks.org/problems/topological-sort/1
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& ed) {
        // code here
        int edges[V]={0};
        
        vector<vector<int>>adj(V);
        for (int i = 0; i < ed.size(); i++) {
            int u = ed[i][0];
            int v = ed[i][1];

            adj[u].push_back(v);
        }
        for(int i=0;i<V;i++){
            for(auto &it:adj[i]){
                edges[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(edges[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int u=q.front();
            ans.push_back(u);
            q.pop();
            for(auto &x:adj[u]){
                edges[x]--;
                if(edges[x]==0){
                    q.push(x);
                }
                
            }
            
        }
        return ans;
    }
};