#include<bits/stdc++.h>
using namespace std;

int minDist(vector<int> dist, vector<int> vis){// forgot to use vis
  int n = dist.size(), min = INT_MAX, minInd = -1;
  for(int i = 0;i < n;i++){
    if(dist[i] < min && !vis[i]){
      min = dist[i];
      minInd = i;
    }
  }
  return minInd;
}

void dijk(vector<vector<int> > g, int root){
  int n = g.size();
  vector<int> vis;
  vis.resize(n, false);
  vector<int> dist;
  dist.resize(n, INT_MAX);
  dist[root] = 0;
  for(int i = 0;i < n;i++){
    int curr = minDist(dist, vis);
    vis[curr] = true;
    for(int j = 0;j < n;j++){
      if(!vis[j] && g[curr][j] != 0 && dist[curr]+g[curr][j] < dist[j]){
        dist[j] = dist[curr]+g[curr][j];
      }
    }
  }
  for(int i = 0;i < n;i++){
    cout<<i<<" "<<dist[i]<<endl;
  }
}

int main(){
  vector<vector<int> > g = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    dijk(g, 0); 
}