class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int> > ans;
        ans.resize(n, vector<int> (m, -1));
        deque<pair<pair<int, int>, int> >q;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                
                if(matrix[i][j]==0){
                    q.push_front({{i,j}, 0});
                    ans[i][j]=0;
                }
            }
        }
        
        while(!q.empty()){
            
            int r=q.back().first.first;
            int c=q.back().first.second;
            int s=q.back().second;
            q.pop_back();
            ans[r][c]=s;
            
        }
        return ans;
    }
};