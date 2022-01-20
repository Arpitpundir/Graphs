#include<bits/stdc++.h>
using namespace std;
#define INF 10000
void FloydWarshal(vector<vector<int> > g, int root){
  int n = g.size();
  vector<vector<int> > dist(g);

  for(int k=0;k<n;k++){
    // in kth phase we use vertices(1,2, ....k) as intermediate vertices
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        //if there is a path going through nodes from 1 to k whose cost is less than current value then use this path
        if(dist[i][k]+dist[k][j] < dist[i][j]){
          dist[i][j] = dist[i][k]+dist[k][j];
        }
      }
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<dist[i][j]<<" ";
    }
    cout<<endl;
  }
}

int main(){
  vector<vector<int> > g = {
   {0, INF, -2, INF},
    {4,0,3, INF},
    {INF, INF, 0, 2},
    {
      INF, -1, INF, 0
    }
  };

  FloydWarshal(g, 0);
}