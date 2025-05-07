class State {
public:
    int x;
    int y;
    int dis;
    State(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};


class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int inf = 0x3f3f3f3f;
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> d(n, vector<int>(m, inf));
        vector<vector<int>> v(n, vector<int>(m, 0));

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        d[0][0] = 0;

        auto cmp = [](const State& a, const State& b) { return a.dis > b.dis; };

        priority_queue<State, vector<State>, decltype(cmp)> q(cmp);
        q.push(State(0,0,0));

        while(!q.empty()){
            State current=q.top();
            q.pop();
            int nx=current.x,ny=current.y;
            
            if(v[nx][ny])continue;
            v[nx][ny]=1;
            for(int i=0;i<4;i++){
                int nnx=nx+dirs[i][0];
                int nny=ny+dirs[i][1];
                if(nnx<0 || nnx>=n || nny<0 || nny>=m )continue;
                int dist=max(d[current.x][current.y],moveTime[nnx][nny])+1;
                if(d[nnx][nny]>dist){
                    d[nnx][nny]=dist;
                    q.push(State(nnx,nny,dist));
                }
            }
        }
        return d[n-1][m-1];
    }
};