class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int cnt=1;
        int ka=0;
        int precnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i])
            {
                cnt++;
            }else{
                precnt=cnt;
                cnt=1;
            
            }
            ka=max(ka,min(precnt,cnt));
            ka=max(ka,cnt/2);
        }
       
        if(ka>=k){
            return true;
        }
        return false;

    }
};