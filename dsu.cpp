#include<bits/stdc++.h>
using namespace std;
class dsu{
  public:
  int n;
  vector<int> parent;
  dsu(int n){
    this->n = n;
    this->parent.resize(n);
    for(int i = 0;i < n;i++){
      this.parent[i] = i;
    }
  }

  int getSp(int i){
    if(parent[i] == i){
      return i;
    }else{
      parent[i] = getSp(parent[i]);
      return parent[i];
    }
  }

  int unite(int x, int y){
    int spx = getSp(x);
    int spy = getSp(y);
    if(spx != spy){
      parent[x] = y;
    }
  }
}

int main(){}