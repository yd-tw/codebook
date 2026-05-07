bs dp;
dp[0] = 1; // 0 就是不取東西就能湊出來
for(int i = 1; i <= n;++i){
    dp = dp | (dp<<A[i]);
}
cout << dp[K];