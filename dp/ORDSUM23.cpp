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

ll MOD=1000000007;
ll dp[1000001]={0};

void setdp(){
     dp[2]=1;
    dp[3]=1;
     for(int i=4;i<=1000000;i++){
        dp[i]=(dp[i-2]+dp[i-3])%MOD;
    }
}

void solve() {
    ll n;
    cin >> n;
    cout<<dp[n]<<"\n";
}

int main() {
    fastio;
    setdp();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}