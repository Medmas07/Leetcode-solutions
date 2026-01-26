class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(),arr.end());
        int min_diff=1000000;
        int i_start=0;
        for(int i=0;i<arr.size()-1;i++){
            int tmp=-arr[i]+arr[i+1];
            if(tmp<min_diff){
                min_diff=tmp;
                i_start=i;
            }

        }
        for(int i=i_start;i<arr.size()-1;i++){
            vector<int> tmp(2);
            int t=-arr[i]+arr[i+1];
            if(t==min_diff){
                tmp[0]=arr[i];
                tmp[1]=arr[i+1];
                res.push_back(tmp);
            }
            
        }
        return res;
    }
};