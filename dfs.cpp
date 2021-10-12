#include<bits/stdc++.h> 
using namespace std; 

unordered_map<int, vector<int> > g; 
vector<bool> vis;

void DFS(int v) 
{ 
 
	vis[v] = true; 
	cout << v << " "; 

	int l = g[v].size(); 
	for (int i = 0; i < l; i++) 
		if (!vis[g[v][i]]) 
			DFS(g[v][i]); 
} 

int main() 
{

  int n = 4;
  vis.resize(n, false);

  g[0].push_back(1);
  g[0].push_back(2);
  g[1].push_back(2);
  g[2].push_back(0);
  g[2].push_back(3);
  g[3].push_back(3);

  DFS(2); 

	return 0; 
} 
