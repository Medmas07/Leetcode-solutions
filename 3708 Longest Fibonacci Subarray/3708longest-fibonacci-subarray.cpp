class Solution {
public:
    bool isFibonacci(vector<int>& tab){
        if(tab.size()<=2)return true;
        for(int i=2;i<tab.size();i++){
            if(tab[i]!=tab[i-1]+tab[i-2]){
                return false;
            }
        }

        return true;
    }
    int longestSubarray(vector<int>& nums) {
        if(nums.size()<=2)return nums.size();
        int res=0;
        int tmp=2;
        
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i+2]==nums[i]+nums[i+1]){
                tmp++;
            }else{
                if(tmp>res)res=tmp;
                tmp=2;
            }
        }
        if(tmp>res)return tmp;
        return res;
    }
};