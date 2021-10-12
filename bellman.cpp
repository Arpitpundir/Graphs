#include<bits/stdc++.h>
using namespace std;

void bellman(vector<vector<int> > edges, int src, int n){

  int l = edges.size();
  vector<int> dist;
  dist.resize(n, INT_MAX);
  dist[src] = 0;

  for(int i = 0;i < n;i++){
    for(int j = 0;j < l;j++){

      int from = edges[j][0];
      int to = edges[j][1];
      int weight = edges[j][2];

      if(dist[from] != INT_MAX && dist[from] + weight < dist[to]){

        dist[to] = dist[from] + weight;
      }
    }
  }

  for(int j = 0; j < l;j++){
    int from = edges[j][0];
    int to = edges[j][1];
    int weight = edges[j][2];

    if(dist[from] != INT_MAX && dist[from] + weight < dist[to]){

      cout<<"There is a negative cycle in the graph"<<endl;
      exit(0);
    }    
  }

  for(int i = 0;i < n;i++){

    cout<<i+1<<" "<<dist[i]<<endl;
  }
}

int main(){
  int n, m;
  cin>>n>>m;

  vector<vector<int> > edges;

  for(int i = 0;i < m;i++){

    int from, to, weight;
    cin>>from>>to>>weight;
    edges.push_back({from-1, to-1, weight});
  }

  bellman(edges, 0, n);
}