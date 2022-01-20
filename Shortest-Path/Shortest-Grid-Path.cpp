#include<bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int> > g){
  int n = g.size(), m = g[0].size();
  vector<vector<int> > dist(n, vector<int>(m, INT_MAX));
  set<pair<int, pair<int, int> > > s;
  s.insert({g[0][0], {0,0}});

  while(!s.empty()){
    auto currPair = s.begin();
    s.erase(currPair);
    int currDist = currPair->first, currX = currPair->second.first, currY = currPair->second.second;
    if(currY == n-1 && currX == m-1){
      return currDist;
    }
    dist[0][0] = g[0][0]; //mistake 

    vector<vector<int> > dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    for(int i=0;i<4;i++){
      int x = currX+dir[i][0], y = currY+dir[i][1];

      if(x<0||x>=m||y<0||y>=n) continue; // mistake

      if(currDist+g[y][x]<dist[y][x]){
        auto f = s.find({dist[y][x], {x,y}});
        if(f != s.end()){
          s.erase(f);
        }
        int temp = currDist+g[y][x];
        s.insert({temp, {x,y}});

        dist[y][x] = temp; // mistake

      }
    }
  }
}

int main(){
  vector<vector<int> > g;
  int n, m;
  cin>>n>>m;
  g.resize(n);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int temp;
      cin>>temp;
      g[i].push_back(temp);
    }
  }

  cout<<shortestPath(g);
  return 0;
}