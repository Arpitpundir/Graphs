#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<int> dis, low;
vector<bool> vis;
int tim = 1;
// we are using set because a node can be articulation point from multiple edges, so it can be inserted multiples and we need to maintain a single copy of node
set<int> articulationPoint;
vector<pair<int, int> > articulationBridge;

void FindArticulationPointBridge(int currNode, int par){

  vis[currNode] = true;
  dis[currNode] = low[currNode] = tim++;
  int child = 0;
  for(auto nbr: g[currNode]){
    child++;
    if(!vis[nbr]){
      FindArticulationPointBridge(nbr, currNode);
      low[currNode] = min(low[currNode], low[nbr]);
      if(low[nbr] > dis[currNode]){
        articulationBridge.push_back({currNode, nbr});
      }

      if(par!= 0 && low[nbr] >= dis[currNode]){
        cout<<currNode<<" "<<nbr<<" "<<dis[currNode]<<" "<<low[nbr]<<endl;
        articulationPoint.insert(currNode);
      }
    }else if(nbr!=par){
      low[currNode] = min(low[currNode], dis[nbr]);
    }
  }

  if(par == 0 && child > 1){
    articulationPoint.insert(par);
  }
}
int main(){
  int n;
  cin>>n;
  g.resize(n), vis.resize(n, false), dis.resize(n), low.resize(n);

  int m;
  cin>>m;
  while(m--){
    int st, end;
    cin>>st>>end;
    g[st].push_back(end);
    g[end].push_back(st);
  }

  FindArticulationPointBridge(0, -1);

  cout<<"Articulation Points are:  "<<endl;
  for(auto curr: articulationPoint){
    cout<<curr<<" ";
  }

  cout<<endl<<"Articulation Bridges are: "<<endl;

  for(auto currEdge: articulationBridge){
    cout<<currEdge.first<<" "<<currEdge.second<<endl;
  }
}