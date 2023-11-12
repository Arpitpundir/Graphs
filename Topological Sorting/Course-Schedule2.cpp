class Solution {
    private: 
    vector<int> result;
    vector<int> visited;
public:
    bool topologicalOrder(int node, vector<vector<int> > &graph){
        visited[node] = 1;
        for(int i=0;i<graph[node].size();i++){
            int nbr = graph[node][i];
            if(visited[nbr] == 0 && !topologicalOrder(nbr, graph)){
                return false;
            }else if(visited[nbr] == 1){
                return false;
            }
        }
        visited[node] = 2;
        result.push_back(node);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        result.resize(0);
        visited.resize(numCourses, 0);
        vector<vector<int> > graph;
        graph.resize(numCourses);
        int edgesN = prerequisites.size();
        for(int i=0;i<edgesN;i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i=0;i<numCourses;i++){
            if(!visited[i] && !topologicalOrder(i, graph)){
                return *(new vector<int>());
            }
        }
        return result;

    }
};