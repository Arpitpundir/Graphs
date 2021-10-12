#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > gr, grr, comp;
vector<int> vis;
vector<int> order;

void dfs(int i){

  vis[i] = 1;
  int l = gr[i].size();

  for(int j = 0;j < l;j++){

    int temp = gr[i][j];
    if(!vis[temp]){

      dfs(temp);
    }
  }
  order.push_back(i);
}

void dfs_r(int i, int col){

  comp[col].push_back(i);
  cout<<i<<"->"<<col<<endl;
  vis[i] = 1;
  int l = grr[i].size();

  for(int j = 0;j < l;j++){

    int temp = grr[i][j];
    if(!vis[temp]){

      dfs_r(temp, col);
    }
  }
}
int main(){

  int n, m;
  cin>>n>>m;
  vis.resize(n, 0);
  gr.resize(n);
  grr.resize(n);

  for(int i = 0;i < m;i++){

    int x, y;
    cin>>x>>y;
    gr[x].push_back(y);
    grr[y].push_back(x);
  }

  for(int i = 0;i < n;i++){

    if(!vis[i]){

      dfs(i);
    }
  }

  vis.resize(0);
  vis.resize(n, 0);
  int col = 0;
  
  for(int i = n-1;i >= 0;i--){
    comp.push_back({});
    if(!vis[order[i]]){

      cout<<order[i]<<endl;
      dfs_r(order[i], col);
      col++;
    }
  }

  int l = comp.size();

  for(int i = 0;i < l;i++){

    cout<<"C"<<i+1<<" ";
    int l2 = comp[i].size();

    for(int j = 0;j < l2;j++){

      cout<<comp[i][j]<<" ";
    }
    cout<<endl;
  }
}
