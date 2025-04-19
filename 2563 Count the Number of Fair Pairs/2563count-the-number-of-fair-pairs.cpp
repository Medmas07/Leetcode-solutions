 #include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
    long long c=0;
    sort(nums.begin(), nums.end());
    
    for(int i=0;i<nums.size();i++){
        auto it_lower = std::lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i]);

            
        auto it_upper = std::upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i]);

        
        c+=(it_upper-it_lower);

    }

    return c;


    }
};