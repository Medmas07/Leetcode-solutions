class Solution {
public:
    /*int dfs(int i,int j , vector<vector<int>>& triangle){
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        else{
            int sum=triangle[i][j]+dfs(i+1,j,triangle);
            int sum1=triangle[i][j]+dfs(i+1,j+1,triangle);
            
            if(sum < sum1){
                return sum;
            }else{
                return sum1;
            }
            
        }
    }*/
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> test;
        test.push_back(triangle[0][0]);
        for(int row=1;row<triangle.size();row++){
            vector<int> test1;
            for(int j=0;j<triangle[row].size();j++){
                if(j!=0 && j!=triangle[row].size()-1){
                    test1.push_back(min(test[j-1]+triangle[row][j],test[j]+triangle[row][j]));
                }
                else if(j==0){
                    test1.push_back(test[j]+triangle[row][j]);
                }
                else{
                    test1.push_back(test[j-1]+triangle[row][j]);
                }
                
                
                
            }
            test=test1;
           
        }
        return *min_element(test.begin(), test.end());
    }
};