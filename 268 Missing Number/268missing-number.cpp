#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums[nums.size()-1];i++){
            if(i!=nums[i]){
                return i;
            }
        }
        return nums.size();
    }
};