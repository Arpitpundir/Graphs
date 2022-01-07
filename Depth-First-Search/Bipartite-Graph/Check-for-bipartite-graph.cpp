#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int> > g; 
vector<int> vis;

bool isBipartite(int node, int parent, int parentCol){
  vis[node]=3-parentCol;
  int nbrs = g[node].size();
  bool ans = true;
  for(int i=0;i<nbrs;i++){
    if(!vis[g[node][i]] && !isBipartite(g[node][i],node, vis[node])){
      return false;
    }else if(g[node][i]!=parent && vis[node] == vis[g[node][i]]){
      // there is a cycle becuase we have found a back edge
      // this cycle contains odd number of nodes since color of ancestor and curr node is same
      return false;
    }
  }
  return ans;
}

int main(){
  int n = 4;
  vis.resize(n, false);
    g[1].push_back(0); 
    g[0].push_back(2); 
    g[2].push_back(1); 
    g[0].push_back(3); 
    g[3].push_back(4); 
    cout<<isBipartite(0, -1, 2);
  
}