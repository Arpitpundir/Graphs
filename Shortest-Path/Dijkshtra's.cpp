#include<bits/stdc++.h>
using namespace std;
void Dijkshtra(vector<vector<pair<int, int> > > g, int root){
  int n = g.size();
  vector<int> dist(n, INT_MAX);
  set<pair<int, int> > s;
  dist[root] = 0; 
  s.insert({0, root});

  while(!s.empty()){
    auto currPair = s.begin();
    int currDist = currPair->first, currNode = currPair->second;
    s.erase(currPair);
    for(int i=0;i<g[currNode].size();i++){
      int nbr = g[currNode][i].first, currEdge = g[currNode][i].second;
      if(currEdge+currDist < dist[nbr]){
        auto f = s.find({dist[nbr], nbr});
        if(f != s.end()){
          s.erase(f);
        }
        dist[nbr] = currDist+currEdge;
        s.insert({dist[nbr], nbr});
      }
    }
  }
  for(int i = 0;i < n;i++){
    cout<<i<<" "<<dist[i]<<endl;
  }
}

int main(){
  vector<vector<pair<int, int> > >g;
  g.resize(5);
    g[1].push_back({0,1}); 
    g[0].push_back({2,2}); 
    g[2].push_back({3,3}); 
    g[0].push_back({3,3}); 
    g[3].push_back({4,4});

    Dijkshtra(g, 1);
}