#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int> > g1; 
vector<bool> vis;
vector<int> parent;

bool printCycle(int v, int par){
  if(vis[v]){
    return false;
  }
  parent[v] = par;
  vis[v] = true;
  int l = g1[v].size();

  for(int i = 0;i < l;i++){
    if(!vis[g1[v][i]]){
      if(printCycle(g1[v][i], v)){
        return true;
      }
    }else if(g1[v][i] != par){
      int ancestor = g1[v][i]; 
      while(v != ancestor){
        cout<<v<<" ";
        v = parent[v];
      }
      cout<<v<<" ";
      return true;
    }
  }
  return false;
}

int main(){

  int n = 4;
  vis.resize(n, false);
  parent.resize(n, -1);  
    g1[1].push_back(0); 
    g1[0].push_back(2); 
    g1[2].push_back(1); 
    g1[0].push_back(3); 
    g1[3].push_back(4); 
    printCycle(0, -1);
  
}