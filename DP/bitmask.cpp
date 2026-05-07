for(int i = 0; i < n;++i) dp[(1<<i)][i] = true; // 初始化 (自已能走到自己)
for(int s = 1; s < (1<<n);++s){
    for(int j = 0; j < n;++j){
        if(s & (1<<j)) continue; 
        // s 還不能經過 j，因為一個點只能經過一次
        for(int i = 0; i < n;++i){ // 窮舉 s 內的終點
            if(!(s & (1<<i))) continue; // s 必須得經過 i
            if(edge[i][j]){ //有 i -> j 的邊
                  dp[s | (1<<j)][j] |= dp[s][i];  
            } 
        }
    }
}
bool ans = false;
for(int i = 0; i < n;++i) ans |= dp[(1<<n)-1][i];