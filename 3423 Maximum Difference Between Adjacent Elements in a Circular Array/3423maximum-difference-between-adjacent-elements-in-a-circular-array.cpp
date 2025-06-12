class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int max_diff=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(abs(nums[i]-nums[i-1])>max_diff){
                max_diff=abs(nums[i]-nums[i-1]);
            }
        }
        if(abs(nums[0]-nums[n-1])>max_diff){
            max_diff=abs(nums[0]-nums[n-1]);
        }
        return max_diff;
    }
};