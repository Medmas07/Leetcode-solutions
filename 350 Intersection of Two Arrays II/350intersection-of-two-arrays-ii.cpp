class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp(1001,0);
        for(int i=0;i<nums1.size();i++){
            tmp[nums1[i]]++;
        }
         vector<int> tmp1(1001,0);
        for(int i=0;i<nums2.size();i++){
            tmp1[nums2[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<tmp1.size();i++){
            if(tmp[i]!=0){
                for(int j=0;j<((tmp[i]<tmp1[i])?tmp[i]:tmp1[i]);j++){
                    ans.push_back(i);
                }
                
            }
        }
        return ans;
    }
};