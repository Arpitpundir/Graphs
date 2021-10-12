#include<bits/stdc++.h>
using namespace std;

void floodFill(int x, int y, int prevCol, int newCol, vector<vector<int> > &screen){
  int n = screen.size();
  int m = screen[0].size();
  if(x < 0||y<0||x >= m|| y >= n){
    return;
  }
  if(screen[x][y] != prevCol){
    return;
  }
  screen[x][y] = newCol;
  floodFill(x+1, y, prevCol, newCol, screen);
  floodFill(x-1, y, prevCol, newCol, screen);
  floodFill(x, y+1, prevCol, newCol, screen);
  floodFill(x, y-1, prevCol, newCol, screen);
  return;
}

int main(){
  vector<vector<int> > screen = {{1, 1, 1, 1, 1, 1, 1, 1}, 
                      {1, 1, 1, 1, 1, 1, 0, 0}, 
                      {1, 0, 0, 1, 1, 0, 1, 1}, 
                      {1, 2, 2, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 2, 2, 0}, 
                      {1, 1, 1, 1, 1, 2, 1, 1}, 
                      {1, 1, 1, 1, 1, 2, 2, 1}, 
                     }; 
  int x = 4, y = 4, newCol = 3;
  floodFill(x, y, screen[x][y], newCol, screen);
  for(int i = 0;i < 8;i++){
    for(int j = 0;j < 8;j++){
      cout<<screen[i][j]<<" ";
    }
    cout<<endl;
  }
}