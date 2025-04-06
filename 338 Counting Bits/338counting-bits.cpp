class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            int t=i;
            while(t){
                if(t&1){
                    ans[i]+=1;
                }
                t=t>>1;
            }
        }
        return ans;
    }
};