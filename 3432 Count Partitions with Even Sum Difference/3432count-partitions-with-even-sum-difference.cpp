class Solution {
public:
    int countPartitions(vector<int>& nums) {
       int sum1=0,sum2=0;
       for(int i=0;i<nums.size();i++){
        sum2+=nums[i];
       } 
       int res=0;
       for(int i=0;i<nums.size()-1;i++){
        sum1+=nums[i];
        sum2-=nums[i];
        if((sum1-sum2)%2==0){
            res++;
        }
       }
       return res;
    }
};