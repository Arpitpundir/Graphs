class Solution {
public:
    int maxDistance(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<bool> > isVis(n, vector<bool>(n, false));
        queue<pair<pair<int, int>, int > > q;

        int ans = -1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1){
                    q.push(make_pair(make_pair(i,j), 0));
                    isVis[i][j] = true;
                }
            }
        }
        while(!q.empty()){
            auto currNode = q.front();
            q.pop();
            int x = currNode.first.first, y = currNode.first.second;
            int currVal = mat[x][y];
            int currDist = currNode.second;
              if(currVal != 1)
              ans = max(ans, currDist);
            vector<int> xDir = {1,0,-1,0}, yDir = {0,1,0,-1};
            for(int i=0;i<4;i++){
              int tempX = x+xDir[i], tempY = y+yDir[i];
              if(tempX>=0 && tempX<n&&tempY>=0&&tempY<n&&!isVis[tempX][tempY]){
                isVis[tempX][tempY] = true;
                q.push(make_pair(make_pair(tempX, tempY), currDist+1));
              }
            }
        }
        return ans;
    }
};