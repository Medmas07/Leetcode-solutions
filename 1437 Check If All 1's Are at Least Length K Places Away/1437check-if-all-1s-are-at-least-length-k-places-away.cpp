class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int dist = 0;
        int min_dist = nums.size();
        bool started = false;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (started) { 
                    if (dist < min_dist) {
                        min_dist = dist;
                    }
                }
                started = true;
                dist = 0;
            } else {
                if (started) 
                    dist++;
            }
        }

        return (min_dist >= k);
    }
};
