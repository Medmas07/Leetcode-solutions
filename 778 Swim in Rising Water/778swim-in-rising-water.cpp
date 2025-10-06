class Solution {
private:
    map<pair<int, int>, bool> visited;
    vector<vector<int>> neigh = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int swimInWater(vector<vector<int>>& grid) {
       
 
        auto cmp = [](const tuple<int, int, int>& a,
                      const tuple<int, int, int>& b) {
            return get<2>(a) >
                   get<2>(b); 
        };
        int rows=grid.size();
        int cols=grid[0].size();

        priority_queue<
           tuple<int, int, int>,
            vector<tuple<int, int, int>>, 
            decltype(cmp)                           
            >pq(cmp);
        pq.push({0,0,grid[0][0]});
        visited[{0,0}]=true;
        while(!pq.empty()){
            auto[x,y,time]=pq.top();
            pq.pop();
            if(x==rows-1 && y==cols-1){
                return time;
            }
          
            for(auto& dir:neigh){
                int nx=x+dir[0];
                int ny=y+dir[1];

                if(nx<rows && ny<cols && 0<=nx && 0<=ny && !visited[{nx,ny}]){
                    visited[{nx,ny}]=true;
                    int ti=max(time,grid[nx][ny]);
                    pq.push({nx,ny,ti});
                }
            }
        }
        return -1;
    }
};