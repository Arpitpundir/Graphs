#include<bits/stdc++.h>
using namespace std;

void BellmanFord(  vector<pair<pair<int, int>, int> > edges, int n, int root){

  vector<int> dist(n, INT_MAX);
  dist[root] = 0;

  for(int i=0;i<n-1;i++){
    for(int j=0;j<edges.size();j++){
      int startNode = edges[j].first.first,
      endNode = edges[j].first.second,
      edgeWeight = edges[j].second;

      if(dist[startNode]+edgeWeight < dist[endNode]){
        dist[endNode] = dist[startNode]+edgeWeight;
      }
    }
  }

  for(int i=0;i<n-1;i++){
    for(int j=0;j<edges.size();j++){
      int startNode = edges[j].first.first,
      endNode = edges[j].first.second,
      edgeWeight = edges[j].second;

      if(dist[startNode]+edgeWeight < dist[endNode]){
        cout<<"There is a negative edge cycle in graph!!!";
        exit(0);
      }
    }
  }
  for(int i=0;i<n;i++){
    cout<<i<<" "<<dist[i]<<endl;
  }
}

int main(){
  int n, m;
  vector<pair<pair<int, int>, int> > edges;
  cout<<"Enter Input"<<endl;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int startNode, endNode, edgeWeight;
    cin>>startNode>>endNode>>edgeWeight;
    edges.push_back({{startNode, endNode}, edgeWeight});
  }
  BellmanFord(edges, n, 0);
}