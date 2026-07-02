//https://leetcode.com/problems/find-a-safe-walk-through-a-grid/?envType=daily-question&envId=2026-07-02

#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
     bool f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis,int h){
        int n=grid.size();int m=grid[0].size();
        if(h <= 0) return false;
   
        vis[i][j]=1;
        if(i==grid.size()-1&&j==grid[0].size()-1&&h>=1)return true;
         int rr[]={-1,0,1,0};
         int col[]={0,1,0,-1};
         for(int k=0;k<4;k++){
            int rt=i+rr[k];
            int ck=j+col[k];
            if(rt>=0&&rt<n&&ck>=0&&ck<m&&!vis[rt][ck]){
                if(grid[rt][ ck]==1){
                    h--;
                   if( f(rt,ck,grid,vis,h))return true;;
                  h++;
                }
               
                else {
                   if( f(rt,ck,grid,vis,h))return true;
                  
                }
            }
         }
         vis[i][j]=0;
         return false;

     }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();int m=grid[0].size();
        if(grid[0][0] == 1)
    health--;
        vector<vector<int>>vis(n,vector<int>(m,0));
      return   f(0,0,grid,vis,health);
    }
};