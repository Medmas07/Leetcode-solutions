class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        int max_val = *max_element(nums.begin(), nums.end());
        vector<int> hash(max_val);
        for(int i=0;i<nums.size();i++){
            hash[nums[i]-1]++;
        }
        sort(hash.begin(),hash.end(),greater<int>());
        int sum=hash[0];
        for(int i=1;i<hash.size();i++){
            if(hash[i-1]==hash[i]){
                sum+=hash[i];
            }
            else{
                break;
            }
        }
        return sum;
    }
};