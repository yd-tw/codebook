#define ll long long
const ll MOD = 1e9 + 7;                  // 1000000007 是個質數
ll mypow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y & 1) ans = (ans * x) % MOD; // 這裡 % MOD
        x = (x * x) % MOD;               // 這裡 % MOD
        y >>= 1;
    }
    return ans;
}