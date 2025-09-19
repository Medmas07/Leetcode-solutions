class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int> res;
        int count=0;
        int prev=-1;
        for(int i=0;i<nums.size() && count<k;i++){
            if(i==0 || nums[i]!=nums[prev]){
                res.push_back(nums[i]);
                count++;
            }
            prev=i;
        }

        
        return res;
    }
};