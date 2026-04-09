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

ll maxc(vector<ll>& ar, int i, vector<vector<ll>>& dp, bool take) {
    if (i == ar.size()) return 0;

    if (dp[i][take] != -1)
        return dp[i][take];

    ll ans = 0;

    if (take) {
        ll skip = maxc(ar, i + 1, dp, true);
        ll pick = ar[i] + maxc(ar, i + 1, dp, false);
        ans = max(skip, pick);
    } else {
        ans = maxc(ar, i + 1, dp, true);
    }

    return dp[i][take] = ans;
}


void solve(int c) {
    int n;
    cin >> n ;
    vector<ll> ar(n);
    vin(ar,n);
    if(n == 0){
        cout<<"Case "<<c<<": "<<0<<endl;
        return;
    }

    vector<vector<ll>> dp(n,vector<ll>(2,-1));

    cout<<"Case "<<c<<": "<<maxc(ar,0,dp,true)<<endl;


}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    int c=1;
    while (c<=t) {
        solve(c);
        c++;
    }
    return 0;
}