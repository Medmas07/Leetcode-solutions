class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int min_diff = 100000;
        for (int i = 0; i < nums.size() - k+1; i++) {
            int tmp = nums[i + k-1] - nums[i];
            if (tmp < min_diff) {
                min_diff = tmp;
            }
           // cout<<tmp<<endl;
        }
        return min_diff;
    }
};