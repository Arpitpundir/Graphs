#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int> > g;
vector<int> vis;
vector<int> inDeg;
vector<int> ans;

// my approach
void TopologicalSorting(int node){
  vis[node] = 1;
  if(!inDeg[node]){
    ans.push_back(node);
    for(int i=0;i<g[node].size();i++){
      int nbr = g[node][i];
      inDeg[nbr]--;
      if(!vis[nbr] && !inDeg[nbr]){
        TopologicalSorting(nbr);
      }
    }
  }
  return;
}

//tutorial approach
void TopologicalSortTutorial(int node){
  vis[node] = 1;
  for(int i=0;i<g[node].size();i++){
    int nbr = g[node][i];
    if(!vis[nbr]){
      TopologicalSortTutorial(nbr);
    }
  }
  ans.push_back(node);
  return;
}

bool isCycle(int node){
  vis[node] = 1;
  for(int i=0;i<g[node].size();i++){
    int nbr = g[node][i];
    inDeg[nbr]++;
    if(!vis[nbr] && isCycle(nbr)){
      return true;
    }else if(vis[nbr] == 1){
      return true;
    }
  }
  vis[node]=2;
  return false;
}

int main(){
    int n = 5;
    vis.resize(n, 0);  
    inDeg.resize(n, 0);
    g[1].push_back(0); 
    g[0].push_back(2); 
    g[2].push_back(3); 
    g[0].push_back(3); 
    g[3].push_back(4);
    if(isCycle(1)){
      cout<<"There is a cycle topological sorting not possible."<<endl;
    }else{
      vis.assign(n, 0);
      // for(int i=0;i<n;i++){
      //   if(!vis[i]&&!inDeg[i]){
      //     TopologicalSorting(i);
      //   }
      // }
      TopologicalSortTutorial(1);
      reverse(ans.begin(), ans.end());
      for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
      }
    }
    return 0;
}