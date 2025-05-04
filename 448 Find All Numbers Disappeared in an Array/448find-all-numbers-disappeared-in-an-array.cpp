class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int n=nums[nums.size()-1];
        if(nums[0]!=1){
            for(int i=1;i<nums[0];i++){
                ans.push_back(i);
            }
        }
        int j=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]>1){
                for(int k=0;k<nums[i]-nums[i-1]-1;k++){
                    ans.push_back(nums[i-1]+k+1);
                }
            }
        }
        if(nums[nums.size()-1]!=nums.size()){
            for(int i=nums[nums.size()-1]+1;i<=nums.size();i++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};