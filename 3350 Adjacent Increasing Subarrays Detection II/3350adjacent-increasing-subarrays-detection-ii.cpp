class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int cnt=1;
        int precnt=0;
        int ka=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                cnt++;
            }else{
                precnt=cnt;
                cnt=1;
            }
            ka=max(ka,min(cnt,precnt));
            ka=max(ka,cnt/2);
        }

        return ka;
    }
};