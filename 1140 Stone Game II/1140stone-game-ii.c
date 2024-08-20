#define MAXN 100

int dp[MAXN][MAXN]; // DP table

int stoneGameII(int* piles, int pilesSize) {
    // Compute prefix sums
    int prefix_sum[MAXN];
    prefix_sum[0] = piles[0];
    for (int i = 1; i < pilesSize; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + piles[i];
    }

    // Initialize DP table
    memset(dp, -1, sizeof(dp));
    
    // Helper function to compute the maximum number of stones Alice can collect
    int stoneGameIIHelper(int start, int M) {
        if (start >= pilesSize) {
            return 0;
        }
        if (dp[start][M] != -1) {
            return dp[start][M];
        }
        
        int total = prefix_sum[pilesSize - 1] - (start > 0 ? prefix_sum[start - 1] : 0);
        int best = 0;
        
        for (int x = 1; x <= 2 * M && start + x <= pilesSize; x++) {
            int opponent_score = stoneGameIIHelper(start + x, (x > M ? x : M));
            best = (best > total - opponent_score) ? best : total - opponent_score;
        }
        
        dp[start][M] = best;
        return best;
    }
    
    // The result is the maximum number of stones Alice can get starting from index 0 with M = 1
    return stoneGameIIHelper(0, 1);
}

