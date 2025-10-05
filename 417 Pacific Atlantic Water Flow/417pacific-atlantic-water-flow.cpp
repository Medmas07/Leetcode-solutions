class Solution {
public:
    const vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited , int i ,int j){
        int m=heights.size();
        int n=heights[0].size();
        cout<<"i= "<<i<<endl;
        cout<<"j= "<<j<<endl;
        visited[i][j]=true;
        for(vector<int> d : dir){
            int x=i+d[0],y=j+d[1];
            if(x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && heights[x][y] >= heights[i][j]){
                dfs(heights,visited,x,y);
            }
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            dfs(heights,atlantic,i,0);
            dfs(heights,pacific,i,n-1);
        }

        for(int i=0;i<n;i++){
            dfs(heights,atlantic,0,i);
            dfs(heights,pacific,m-1,i);
        }

        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;

    }
};