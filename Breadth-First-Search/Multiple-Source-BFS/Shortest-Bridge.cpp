class Solution {
public:
    void findAllOneFromFirstIsland(int row, int col, vector<vector<int> > &grid){
        int n = grid.size(), m = grid[0].size();
        vector<int> dx{1,0,-1,0}, dy{0,-1,0,1};
        
        queue<pair<pair<int,int>, int> > q;
        q.push({{row, col}, 0});
        grid[row][col] = 2;
        while(!q.empty()){
            int row = q.front().first.first, col = q.front().first.second, currDist = q.front().second;
            q.pop();
            vector<int> dx{1,0,-1,0}, dy{0,-1,0,1};
            for(int i=0;i<4;i++){
                int currCol = col+dx[i], currRow = row+dy[i];
                if(currCol>=0&&currCol<m&&currRow>=0&&currRow<n){
                    if(grid[currRow][currCol] == 1){
                        grid[currRow][currCol] = 2;
                        q.push({{currRow, currCol}, currDist+1});
                    }
                }
            }
        }
        return;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++){
            int found = 0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    findAllOneFromFirstIsland(i, j,grid);
                    found = 1;
                    break;
                }
            }
                            if(found) break;

        }
        
        queue<pair<pair<int,int>, int> > q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j}, 0});
                }
            }
        }
        
        int ans = 0;
        
        while(!q.empty()){
            int row = q.front().first.first, col = q.front().first.second, currDist = q.front().second;
            q.pop();
            vector<int> dx{1,0,-1,0}, dy{0,-1,0,1};
            for(int i=0;i<4;i++){
                int currCol = col+dx[i], currRow = row+dy[i];
                if(currCol>=0&&currCol<m&&currRow>=0&&currRow<n){
                    if(grid[currRow][currCol] == 0){
                        grid[currRow][currCol] = 3;
                        q.push({{currRow, currCol}, currDist+1});
                    }
                    else if(grid[currRow][currCol] == 1){
                        return currDist;
                    }
                }
            }
        }
        return ans;
    }
};