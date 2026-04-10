#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)

#define vin(v,n) for(int i=0;i<n;i++) cin>>v[i];
#define vout(v) for(auto &x : v) cout<<x<<" "; cout<<"\n";

#define YES cout << "YES\n";
#define NO  cout << "NO\n";

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << "\n";
#else
#define debug(x)
#endif

void solve() {
    ll n;
    if (!(cin >> n)) return;
    if (n <= 1) {
        cout << 0 << "\n";
        return;
    }

    vector<ll> ar(n);
    vin(ar, n);

    ll ans = 0;
    // Every reduction between two elements cost max(a, b)
    // The sum of max of all adjacent pairs is the optimal cost.
    rep(i, 0, n - 1) {
        ans += max(ar[i], ar[i+1]);
    }
    cout << ans << "\n";
}

int main() {
    fastio;
    solve();
    return 0;
}