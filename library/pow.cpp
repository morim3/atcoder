
int pow(int x, int n) {
    int ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

long long Pow(long long x, long long n, long long mod) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % mod;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % mod;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;