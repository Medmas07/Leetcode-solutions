#include <vector>
#include <algorithm> // for std::copy
using namespace std;
class NumArray {
public:
    vector<int> t;
    NumArray(vector<int>& nums) {
       copy(nums.begin(), nums.end(), back_inserter(t));
    }
    
    int sumRange(int left, int right) {
        int s=0;
        for(int i=left;i<=right;i++){
            s+=t[i];
        }
        return s;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */