#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> rank;
int Find(int a){
  if(parent[a] == -1){
    return a;
  }
  return Find(parent[a]);
};

void Union(int a, int b){
  int sp1 = Find(a), sp2 = Find(b);

  if(sp1 != sp2){
    if(rank[sp1]<rank[sp2]){
      parent[sp1] = sp2;
      rank[sp2]+=rank[sp1];
      rank[sp1] = 0;
    }else{
      parent[sp2] = sp1;
      rank[sp1]+=rank[sp2];
      rank[sp2] = 0;
    }
  }
}

bool containsCycle(){
  int n = g.size();
  parent.resize(n, -1);
  rank.resize(n, 1);

  for(int i=0;i<g.size();i++){
    int sp1 = Find(g[i][0]), sp2 = Find(g[i][1]);

    if(sp1!=sp2){
      Union(sp1, sp2);
    }else{
      return true;
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