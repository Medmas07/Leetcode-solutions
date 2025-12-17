class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> nb_node_incoming(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            nb_node_incoming[edges[i][1]]++;
        }
        vector<int> res;
        for(int i=0;i<nb_node_incoming.size();i++){
            if(nb_node_incoming[i]==0)
            res.push_back(i);
        }
        
        return res;
    }
};