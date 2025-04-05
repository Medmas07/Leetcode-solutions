#include <vector>
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
    int total = 0;
    backtrack(nums, 0, 0, total);
    return total;
}

void backtrack(vector<int>& nums, int index, int currentXOR, int& total) {
    if (index == nums.size()) {
        total += currentXOR;
        return;
    }
    
    // Include nums[index]
    backtrack(nums, index + 1, currentXOR ^ nums[index], total);
    
    // Exclude nums[index]
    backtrack(nums, index + 1, currentXOR, total);
}
};