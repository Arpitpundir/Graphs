#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int> > g1; 
unordered_map<int, vector<int> > g2; 

vector<bool> vis;

bool isCyclic(int v, int parent){

  if(vis[v]){

    return false;
  }

  vis[v] = true;
  int l = g2[v].size();

  cout<<v<<" "<<l<<endl;

  for(int i = 0;i < l;i++){

    if(!vis[g2[v][i]]){

      if(isCyclic(g2[v][i], v)){
//cout<<v<<" 1 "<<g2[v][i]<<endl;
      return true;
      }
    }else if(g2[v][i] != parent){ //means this child node is visited and it is nto curr parent so i can react from this
    //child node to curr node so there is a cycle
cout<<v<<" 2 "<<g2[v][i]<<endl;

      return true;
    }
  }

  return false;
}

int main(){

  int n = 4;
  vis.resize(n, false);  
    g1[1].push_back(0); 
    g1[0].push_back(2); 
    g1[2].push_back(1); 
    g1[0].push_back(3); 
    g1[3].push_back(4); 
  
    g2[0].push_back(1); 
    g2[1].push_back(2);

    isCyclic(0, -1)? cout << "Graph contains cycle\n":cout << "Graph doesn't contain cycle\n";  
  
}