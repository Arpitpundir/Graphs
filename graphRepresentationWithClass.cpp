#include<bits/stdc++.h>
using namespace std;

class Node{
  // Node contains the data about the node like identifier, edges and other data accn to the question
  public:
  string name;
  vector<string> nbrs;
  Node(string name){
    this->name = name;
  }
};

class Graph{
  // in a simple scenerio grpah only contains a map where every key is the identifier for a particular node and value 
  // is the node whose identifier is this key
  public:
  unordered_map<string, Node*> m;

  Graph(vector<string> cities){
    for(auto city: cities){
      m[city] = new Node(city);
    }
  };

  void addEdge(string x, string y, bool undir = false){
    m[x]->nbrs.push_back(y);
    if(undir){
      m[y]->nbrs.push_back(y);
    }
  }

  void printAdjList(){
    for(auto cityPair: m){
      auto city = cityPair.first;
      Node *currNode = cityPair.second;
      for(auto nbrCity: currNode->nbrs){
        cout<<city<<"->"<<nbrCity<<" ";
      }
      cout<<endl;
    }
  }
};
int main(){
  vector<string> cities = {"Delhi", "London", "Paris", "New York"};
  Graph g(cities);
  g.addEdge("Delhi", "London");
  g.addEdge("New York", "London");
  g.addEdge("Delhi", "Paris");
  g.addEdge("Paris", "New York");

  g.printAdjList();
}