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

void solve(int t_case) {
    int n, r;
    cin >> n >> r;
    vector<int> spy(n, 0), target(n, 0);
    bool spied = false;

    rep(i, 0, r) {
        int u, v;
        cin >> u >> v;
        spy[u] = 1;
        target[v] = 1;
    }

    rep(i, 0, n) {
        if (spy[i] && target[i]) {
            spied = true;
            break;
        }
    }

    cout << "Scenario #" << t_case << ": " << (spied ? "spied" : "spying") << "\n";
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    int i=1;
    while (i<=t) solve(i++);
    return 0;
}