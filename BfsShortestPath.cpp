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

void BfsShortestPath(unordered_map<int, Node*> g, int n, int source){

  vector<bool> isVisited(n,false);
  queue<int>q;
  vector<int> parent(n,-1);
  vector<int> shortestPath(n, INT_MAX);

  q.push(source);
  parent[source] = source;
  shortestPath[source] = -1;
  isVisited[source] = true;

  while(!q.empty()){
    int currNodeVal = q.front();
    cout<<"currNode: "<<currNodeVal<<endl;
    Node *currNode = g[currNodeVal];
    q.pop();
    shortestPath[currNodeVal] = shortestPath[parent[currNodeVal]]+1;
    cout<<"shortestPath "<<shortestPath[currNodeVal]<<endl;
    cout<<"Nbrs"<<endl;
    for(auto currNbrVal: currNode->nbrs){
      if(!isVisited[currNbrVal]){
        cout<<"Unvisited "<<currNbrVal<<endl;
        isVisited[currNbrVal] = true;
        parent[currNbrVal] = currNodeVal;
        q.push(currNbrVal);
      }else{
        cout<<"Visited "<<currNbrVal<<endl;
      }
    }
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

  BfsShortestPath(g, 7, 1);
}