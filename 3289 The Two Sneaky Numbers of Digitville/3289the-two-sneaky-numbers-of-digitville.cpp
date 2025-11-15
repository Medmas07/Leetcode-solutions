class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<bool> mp(nums.size());
        vector<int> res;

        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]){
                res.push_back(nums[i]);
                
            }
            mp[nums[i]]=true;
        }
        return res;
    }
};