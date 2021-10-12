#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int> > g;
vector<bool> vis;

void dfs(int v){

  vis[v] = true;
  cout<<v<<" ";

  int l = g[v].size();

  for(int i = 0;i < l;i++){

    if(!vis[g[v][i]]){
      dfs(g[v][i]);
    }
  }
}

void connCompo(int n){

  for(int i = 0;i < n;i++){

    if(!vis[i]){

      dfs(i);
      cout<<endl;
    }
  }
}

int main(){

  int n = 5;
  vis.resize(n, false);
  g[0].push_back(1);
  g[2].push_back(3);
  g[3].push_back(4);

  connCompo(n);
}