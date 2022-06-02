class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int> > vis;
        vis.resize(n, vector<int>(m,0));
        queue<pair<pair<int,int>, int> > bfsQ;
        int fresh = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    bfsQ.push({{i,j},0});
                }else if(grid[i][j]==1) fresh++;
            }
        }
        
        int ans = 0;
        
        while(!bfsQ.empty()){
            pair<int, int> curr = bfsQ.front().first;
            int currX = curr.first, currY = curr.second;
            int currDuration = bfsQ.front().second;
            bfsQ.pop();
            vector<int> dx{1,0,-1,0}, dy{0,-1,0,1};
            
            for(int i=0;i<4;i++){
                
                if(currX+dx[i] >=0 && currX+dx[i]<n && currY+dy[i]>=0 && currY+dy[i]<m &&grid[currX+dx[i]][currY+dy[i]] == 1 && !vis[currX+dx[i]][currY+dy[i]]){
                    bfsQ.push({{currX+dx[i], currY+dy[i]}, currDuration+1});
                    ans = max(ans, currDuration+1);
                    vis[currX+dx[i]][currY+dy[i]] = 1;
                    fresh--;
                }
            }
        }
        if(fresh>0) return -1;
        
        return ans;
        
    }
};