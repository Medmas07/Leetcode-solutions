class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 1; i < grid.size() - 1; i++) {
            for (int j = 1; j < grid[i].size() - 1; j++) {
                vector<bool> tmp(11);
                for(int w=1;w<=9;w++){
                    tmp[w]=false;
                }
                tmp[grid[i - 1][j - 1]]=1;
                tmp[grid[i - 1][j ]]=1;
                tmp[grid[i - 1][j + 1]]=1;
                tmp[grid[i + 1][j - 1]]=1;
                tmp[grid[i + 1][j ]]=1;
                tmp[grid[i + 1][j + 1]]=1;
                tmp[grid[i][j - 1]]=1;
                tmp[grid[i][j ]]=1;
                tmp[grid[i][j + 1]]=1;
                bool cum=true;
                for(int w=1;w<=9;w++){
                    cum=cum&&tmp[w];
                }
               // cout<<cum<<endl;
                if (grid[i - 1][j - 1] <= 9 && grid[i + 1][j + 1] <= 9 &&
                    grid[i - 1][j + 1] <= 9 && grid[i + 1][j - 1] <= 9 &&
                    grid[i - 1][j - 1] >= 1 && grid[i + 1][j + 1] >= 1 &&
                    grid[i - 1][j + 1] >= 1 && grid[i + 1][j - 1] >= 1) {
                    int sum1 = grid[i - 1][j - 1] + grid[i + 1][j + 1] +
                               grid[i][j],
                        sum2 = grid[i - 1][j + 1] + grid[i + 1][j - 1] +
                               grid[i][j],
                        sum3 = grid[i - 1][j] + grid[i + 1][j] + grid[i][j],
                        sum4 = grid[i][j + 1] + grid[i][j - 1] + grid[i][j],
                        sum5 = grid[i - 1][j - 1] + grid[i - 1][j] +
                               grid[i - 1][j + 1],
                        sum6 = grid[i + 1][j - 1] + grid[i + 1][j] +
                               grid[i + 1][j + 1],
                        sum7 = grid[i - 1][j - 1] + grid[i][j - 1] +
                               grid[i + 1][j - 1],
                        sum8 = grid[i - 1][j + 1] + grid[i][j + 1] +
                               grid[i + 1][j + 1];
                    if (sum1 == sum2 && sum3 == sum4 && sum2 == sum3 &&
                        sum4 == sum5 && sum5 == sum6 && sum6 == sum7 &&
                        sum7 == sum8 & cum) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};