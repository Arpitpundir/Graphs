#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int> > g; 
vector<bool> vis;
vector<bool> isAncestor;

bool isCycle(int v){

  if(vis[v]){

    return false;
  }

  vis[v] = true;
  isAncestor[v] = true;//did not hit mind

  int l = g[v].size();

  for(int i = 0;i < l;i++){

    if(!vis[g[v][i]] && isCycle(g[v][i])){

      return true;
    }else if(isAncestor[g[v][i]]){

      return true;
    }
  }

  isAncestor[v] = false;
  return false;
}

int main(){

  int n = 4;
  vis.resize(n, false);
  isAncestor.resize(n, false);

  g[0].push_back(1);
  g[0].push_back(2);
  g[1].push_back(2);
  g[2].push_back(3);
  //g[3].push_back(3);
  
  if(isCycle(0))
  cout<<"Cycle"<<endl;
  else
  cout<<"No cycle"<<endl;

}