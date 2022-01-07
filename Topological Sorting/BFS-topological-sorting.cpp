#include<bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int> > g;
vector<int> vis;
vector<int> inDeg;
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

vector<int> TopologicalSorting(){
  vector<int> ans;
  int n = g.size();
  queue<int> q;
  for(int i=0;i<n;i++){
    if(!inDeg[i]){
      q.push(i);
    }
  }

  while(!q.empty()){
    int curr = q.front();
    ans.push_back(curr);
    q.pop();
    for(int i=0;i<g[curr].size();i++){
      int nbr = g[curr][i];
      inDeg[nbr]--;
      if(!inDeg[nbr]){
        q.push(nbr);
      }
    }
  }

  return ans;
}

int main(){
    int n = 5;
    vis.resize(n, false);  
    inDeg.resize(n, 0);
    g[1].push_back(0); 
    g[0].push_back(2); 
    g[2].push_back(3); 
    g[0].push_back(3); 
    g[3].push_back(4);
    if(isCycle(1)){
      cout<<"There is a cycle topological sorting not possible."<<endl;
    }else{
      vector<int> toplogicalOrder = TopologicalSorting();
      for(int i=0;i<n;i++){
        cout<<toplogicalOrder[i]<<" ";
      }
    }
    return 0;
}