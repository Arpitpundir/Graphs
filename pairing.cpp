#include<bits/stdc++.h>
using namespace std;

class dsu{
  public:
  int n;
  vector<int> parent;
  vector<int> size;
  dsu(int n){

    this->n = n;
    this->parent.resize(n);
    this->size.resize(n, 1);

    for(int i = 0;i < n;i++){

      this->parent[i] = i;
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

      this->parent[spx] = spy;
      //cout<<x<<" "<<y<<" "<<this->parent[x]<<" "<<this->parent[y]<<endl;
      this->size[spy] += this->size[spx];
      this->size[spx] = 0;
    }
  }
};

int main(){

  int n, m;
  cin>>n>>m;

  dsu g = dsu(n);
  while(m--){

    int temp1, temp2;
    cin>>temp1>>temp2;

    g.unite(temp1, temp2);
  } 

  int ans = 0;

  for(int i = 0; i < n; i++){

    int spi = g.getSp(i);
    //cout<<i<<" "<<g.size[spi]<<endl;
    ans += n - g.size[spi];
  }

  cout<<ans/2<<endl;
}