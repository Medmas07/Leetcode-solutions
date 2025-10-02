class Solution {
public:
    bool dfs(int current,int destination , vector<vector<int>>& graph ,vector<bool>& visited){
        if(current==destination)return true;
        visited[current]=true;
        for(int i=0;i<graph[current].size();i++){
            if(!visited[graph[current][i]]){
                if(dfs(graph[current][i],destination,graph,visited)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false);

        return dfs(source,destination,graph,visited);
    }
};