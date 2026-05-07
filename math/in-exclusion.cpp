for (int s = 1; s < 1<<n; s++) {
    int sign = -1;
    if (__builtin_popcount(s)&1) sign = 1;
    int mul = 1;
    for (int j = 0; j < n; j++) {
        if (s & (1<<j)) {
            mul = mul * a[j];
        }
    }
    ans += sign * (n / mul);
}