class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if(nums.size()<=3){
            return false;
        }
        int p=-1,q=-1;
        int i=1;
        while(i<nums.size() && nums[i-1]<nums[i]){
            i++;
        }
        if(i-1!=0){
        p=i-1;
        
        while(i<nums.size() && nums[i-1]>nums[i]){
            i++;
        }
        if(nums.size()!=i && nums[i-1]!=nums[i])
            q=i-1;
        }
        while(i<nums.size()&&nums[i-1]<nums[i]){i++;}
        //cout<<p<<q<<i<<endl;
        if(p>-1 && q>-1 && q>p && i-1==nums.size()-1){
            return true;
        }
        return false;
    }
};