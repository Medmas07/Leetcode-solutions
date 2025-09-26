class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%3==0){
                continue;
            }
            int a=0;
            int tmp=nums[i];
            while(tmp%3!=0){
                tmp--;
                a++;
            }
            tmp=nums[i];
            int b=0;
            while(tmp%3!=0){
                tmp++;
                b++;
            }
            res+=(a<b)?a:b;
        }
        return res;
    }
};