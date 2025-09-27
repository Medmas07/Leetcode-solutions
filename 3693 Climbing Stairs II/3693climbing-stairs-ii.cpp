class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if (n == 0) return 0;
        if (n == 1) return costs[0] + 1;
        if (n == 2) return costs[1] + min(costs[0] + 1 + 1, 0 + 4 );
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=costs[0]+1;
        int i=2;
        dp[2]=costs[1]+min(dp[i-1]+1,dp[i-2]+4);
        for(int j=3;j<=n;j++){
            dp[j]=costs[j-1]+min({dp[j-1]+1,dp[j-2]+4,dp[j-3]+9});
        }
        return dp[n];
    }
};