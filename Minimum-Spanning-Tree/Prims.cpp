#include<bits/stdc++.h>
using namespace std;
class compare{
  public:
  operator()(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
  }
};

vector<vector<pair<int, int> > > g;
void PrimsAlgo(){
  int n = g.size();
  // a vector to store nodes which are included in mst
  vector<int> vis;
  vis.resize(n, false);

  // a min heap to store active edges
  priority_queue<pair<int, int>,  vector<pair<int, int> >, compare> pq;

  //starting with source node
  pq.push({0,0});

  int totalTreeCost = 0;
  while(!pq.empty()){
    auto curr = pq.top();
    pq.pop();
    int currNode = curr.second, currWeight = curr.first;
    if(vis[currNode]){ // mistake due to not knowing how algorithm works on ground
    // since same nodes can be in pq multiple edges due to multiple edges but if a node is processed once so cost has already been added to totalCost once
    // its edges are already been processed once then from next time it should be ignored, because obv this time weight of edge would be more
      continue;
    }
    vis[currNode] = true;//mistake
    totalTreeCost+=currWeight;

    for(auto ele: g[currNode]){
      int edgeWeight = ele.first, edgeNode = ele.second;
      if(!vis[edgeNode]){
        pq.push({edgeWeight, edgeNode});
      }
    }
  }
  cout<<totalTreeCost<<endl;
}

int main(){
  int n;
  cin>>n;
  g.resize(n);

  int m;
  cin>>m;
  while(m--){
    int st, end, weight;
    cin>>st>>end>>weight;
    g[st].push_back({weight, end});
    g[end].push_back({weight, st});
  }

  PrimsAlgo();
  return 0;
}