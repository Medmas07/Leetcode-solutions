class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> t;
        std::unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++)
        {
            //  if(m.count(target-nums[i])==1)
            // {
            //     t.push_back(i);
            //     t.push_back(m[target-nums[i]]);
            //     break;
            // }
            if (m.find(target-nums[i]) != m.end()) {
                return {m[target-nums[i]], i};
            }
            m[nums[i]]=i;
        }
        return t;
    }
};