/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    
    if(!node){
        return NULL;
    }
    
    UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
    m[node] = root;
        
    int l = node->neighbors.size();
    for(int i = 0;i < l;i++){
        
        if(m.find(node->neighbors[i]) == m.end())
        root->neighbors.push_back(cloneGraph(node->neighbors[i]));
        else
        root->neighbors.push_back(m[node->neighbors[i]]);
    }
    
    return root;
}