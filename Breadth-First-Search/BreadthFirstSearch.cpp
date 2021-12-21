#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int val;
  vector<int> nbrs;
  Node(int val){
    this->val = val;
  }
};

void bfs(unordered_map<int, Node*> &g, int n, int source) {
  vector<bool> isVisited(n,false);
  queue<int> q;

  q.push(source);
  isVisited[source] = true;

  while(!q.empty()){
    int currNodeVal = q.front();
    q.pop();
    Node *currNode = g[currNodeVal];
    for(auto currNbr: currNode->nbrs){
      if(!isVisited[currNbr]){
        q.push(currNbr);
        isVisited[currNbr] = true;
      }else{
        cout<<"oops a back Edge"<<" "<<currNode<<" "<<currNbr<<endl;
      }
    }
    cout<<currNodeVal<<endl;
  }
}

void addEdge(unordered_map<int, Node*> &g, int x, int y, bool uniDirec = false){
  g[x]->nbrs.push_back(y);
  if(!uniDirec){
    g[y]->nbrs.push_back(x);
  }
}

int main(){
  int n = 7;
  unordered_map<int, Node*> g;
  for(int i=0;i<n;i++){
    Node *currNode = new Node(i);
    g[i] = currNode;
  }
  addEdge(g,1,0);
  addEdge(g,1,2);
  addEdge(g,2,3);
  addEdge(g,4,0);
  addEdge(g,4,3);
  addEdge(g,4,5);
  addEdge(g,3,5);
  addEdge(g,5,6);

  bfs(g,n,1);
}