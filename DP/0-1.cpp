for(int i = 1; i <= n;++i){
for(int w = W; w >= 0;--w)
    dp[w] = max(w - c[i] >= 0 ? dp[w - c[i]] + v[i] : 0,dp[w]);}