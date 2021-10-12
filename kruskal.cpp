#include<bits/stdc++.h>
using namespace std;

class dsu{

  public:
  vector<int> parent;
  int n;
  dsu(int n){

    this->n = n;
    this->parent.resize(n);

    for(int i = 0;i < n;i++){

      this->parent[i] = i;
    }
  }

  int getP(int i){

    if(this->parent[i] != i){

      this->parent[i] = getP(this->parent[i]);
    }

    return this->parent[i];
  }

  void unite(int x, int y){

    int px = getP(x);
    int py = getP(y);


    if(px != py){

      this->parent[px] = py;
    }else{

      cout<<"this edge will make an cycle."<<endl;
      return;
    }
  }
};

int kruskal(vector<vector<int> > edges, int n){

  sort(edges.begin(), edges.end());
  int m = edges.size(), ans = 0;
  dsu g = dsu(n);

  for(int i = 0;i < m;i++){

    int w = edges[i][0];
    int x = edges[i][1];
    int y = edges[i][2];

    cout<<w<<" "<<x<<" "<<y<<endl;
   /* if(g.getP(x) != g.getP(y)){

      g.unite(x, y);
      ans += w;
      //cout<<ans<<endl;

      cout<<w<<" "<<" "<<x<<" "<<y<<endl;
    }*/
  }
  return ans;
}
int main(){
  
  int n, m;
  cin>>n>>m;
  vector<vector<int>> edges;

  for(int i = 0;i < m;i++){

    int x, y, w;
    cin>>x>>y>>w;
    edges.push_back({w, x, y});
  }

  cout<<kruskal(edges, n)<<endl;
}