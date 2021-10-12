/*Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally 
connected group of 0s and a closed island is an island totally (all left, top, right, bottom) 
surrounded by 1s.
Return the number of closed islands.*/

class solution {
  public:
  int n, m;
  vector<vector<int> > vis;
  vector<vector<int> > g;
  bool isSourr(int i, int j){
    if(i<0||j<0||i>n-1||j>m-1){
      return false;
    }
    if(g[i][j] == 1){
      return true;
    }

    g[i][j] = 1;
    
    bool ans = true;
    bool ans1 = isSourr(i+1, j);
    bool ans2 = isSourr(i-1, j);
    bool ans3 = isSourr(i, j-1);
    bool ans4 = isSourr(i, j+1);

    return ans1&&ans2&&ans3&&ans4;
  }
}