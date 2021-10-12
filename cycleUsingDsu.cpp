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

int main(){
  int n;
  cin>>n;
  dsu g = dsu(n);
  int m;
  cin>>m;
  while(m--){
    int x, y;
    cin>>x>>y;
    g.unite(x, y);
  }
}