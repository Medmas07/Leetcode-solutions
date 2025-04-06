#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        map<int,vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int max=0;
        int i_max=0;
        for(int i=0;i<n;i++){
            
            ans[i]={nums[i]};
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && ans[i].size()<ans[j].size()+1){
                    ans[i]=ans[j];
                    ans[i].push_back(nums[i]);
                }
            }
            if(ans[i].size()>max){
                max=ans[i].size();
                i_max=i;
            }
        }
        return ans[i_max];
    }
};