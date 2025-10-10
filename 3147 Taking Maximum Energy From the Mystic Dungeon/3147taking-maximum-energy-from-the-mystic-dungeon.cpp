class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int res=INT_MIN;
        int n=energy.size();
        vector<int> prefix_sum(n);
        for(int i=n-1;0<=i;i--){
            prefix_sum[i]=energy[i]+((i<n-k)?prefix_sum[i+k]:0);
            res=max(res,prefix_sum[i]);

        }
       
        
        return res;
    }
};