#include<bits/stdc++.h>
using namespace std;

void prims(){

  int n, m;
  cin>>n>>m;
  vector<int> vis;
  vis.resize(n+1, 0);

  vector<vector<pair<int, int> > > g;
  g.resize(n+1);
  for(int i = 0;i < m;i++){

    int x, y, w;
    cin>>x>>y>>w;

    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;

  long long int mst = 0;
  pq.push({0,1});

  while(!pq.empty()){

    pair<int, int> curr = pq.top();
    pq.pop();
    int to = curr.second;
    int weight = curr.first;

    if(vis[to])
    continue;

    mst += weight;
    vis[to] = true;

    for(auto x:g[to]){

      if(!vis[x.first]){

        pq.push({x.second, x.first});// important because comparison should be done by weights
      }
    }
  }

  cout<<mst<<endl;
}

int main(){
  prims();
}