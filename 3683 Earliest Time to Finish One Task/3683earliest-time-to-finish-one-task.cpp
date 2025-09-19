class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int max=1000;
        for(int i=0;i<tasks.size();i++){
            if((tasks[i][0]+tasks[i][1])<max){
                max=tasks[i][0]+tasks[i][1];
            }
        }
        return max;
    }
};