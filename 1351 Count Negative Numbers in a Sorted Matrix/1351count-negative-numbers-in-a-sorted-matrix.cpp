class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res=0;
        for(int  i=grid.size()-1;0<=i;i--){
            for(int j=grid[i].size()-1;0<=j;j--){
                if(grid[i][j]<0){
                    res++;
                }else{
                    break;
                }
            }
        }
        return res;
    }
};