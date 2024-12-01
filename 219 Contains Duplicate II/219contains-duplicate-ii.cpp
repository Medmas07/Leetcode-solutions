class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> t;
        set<int> numSet(nums.begin(),nums.end());
        if(nums.size()==numSet.size())
        {
            return false;
        }
        for(int i=0;i<nums.size();i++)
        {
            int num=nums[i];
            if(t.find(num)!=t.end() )
            {
                if((i-t[num])<=k){
                    return true;
                }
            }
            t[num]=i;
            
        }
        return false;
    }
};