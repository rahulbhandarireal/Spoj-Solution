#include <bits/stdc++.h>
using namespace std;
const int MOD = 10000007;

long long modpow(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    long long n, k;
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;
        long long ans = (2 * modpow(n - 1, k)) % MOD;
        ans = (ans + 2 * modpow(n - 1, n-1)) % MOD;
        ans = (ans + modpow(n, k)) % MOD;
        ans = (ans + modpow(n, n)) % MOD;
        cout << ans % MOD << "\n";
    }
    return 0;
}
