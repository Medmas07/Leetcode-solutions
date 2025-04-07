#include<vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
        }
        if(s%2!=0){
            return false;
        }
        int target=s/2;
        vector<bool> dp(target+1,false);
        dp[0]=true;
        for(int i=0;i<nums.size();i++){
            for(int j=target;j>=nums[i];j--){
                dp[j]=dp[j]||dp[j-nums[i]];
                if(nums[i]==target)return true;
            }   
         }
         return dp[target];

    }
};