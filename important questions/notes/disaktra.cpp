//confusion between to use dist[node ] or use d;
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back({v,edges[i][2]});
            adj[v].push_back({u,edges[i][2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int>dist(V,1e9);
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
           // if(d > dist[node]) continue;
            for(auto &x:adj[node]){
                int curnode=x.first;
                int dis=x.second;
                if(dist[node]+dis<dist[curnode]){
                    dist[curnode]=dis+dist[node];
                    pq.push({dist[curnode], curnode});
                    
                }
            }
        }
        return dist;
    }
};