class Solution {
public:
    void dfs(int i,vector<vector<int>>& graph,vector<vector<int>>& tmp_matrix,vector<int>& path,int n){
        if(i==n-1){
            path.push_back(i);
            tmp_matrix.push_back(path);
        }
        else{
            path.push_back(i);
            for(int j=0;j<graph[i].size();j++){
                vector<int>tmp=path;
                dfs(graph[i][j],graph,tmp_matrix,tmp,n);
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        int n = graph.size();
        vector<int> tmp;
        vector<vector<int>> tmp_matrix;
        dfs(0,graph,tmp_matrix,tmp,n);
        return tmp_matrix;
        /*while (!sett.empty()) {

            for (int i = 0; i < graph[current].size(); i++) {
                vector<int> tmp1 = tmp;
                tmp1.push_back(graph[current][k]);
                tmp_matrix.push_back(tmp1);
            }
        }*/
    }
}; 