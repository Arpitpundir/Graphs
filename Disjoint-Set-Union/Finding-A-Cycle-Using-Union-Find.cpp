#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<pair<int, int> > g;

int Find(int a){
  if(parent[a] == -1){
    return a;
  }
  return Find(parent[a]);
}

void Union(int a, int b){
  int sp1 = Find(a);
  int sp2 = Find(b);
  if(sp1 != sp2){
    parent[sp2] = sp1;
  }
  return;
}

bool containsCycle(){
  for(int i=0;i<g.size();i++){
    int a = g[i].first, b = g[i].second;
    int sp1 = Find(a), sp2 = Find(b);
    if(sp1 == sp2){
      return true;
    }else{
      Union(sp1, sp2);
    }
  }
  return false;
}
int main(){
  int n;
  cin>>n;
  parent.resize(n, -1);

  int m;
  cin>>m;
  while(m--){
    int st, end;
    cin>>st>>end;
    g.push_back({st,end});
  }
  cout<<containsCycle()<<endl;
}