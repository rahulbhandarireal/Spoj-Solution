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

int MOD=10000007;

ll recr( vector<vector<ll>>& dp,int i,int rem,int fr,int tf){

    // if muffins less than equal to 0 return 0;
    if(rem <=0 ) return 0ll;
    // for last friend give all muffins
    if(i == tf ) return 1ll; 
   
    // a 2d dp for storing number of ways
    if(dp[i][rem] != -1) return dp[i][rem];

    ll sum=0;
    for(int j=1;j<=(rem -(fr-1));j++){
        sum=(sum%MOD+recr(dp,i+1,rem-j,fr-1,tf))%MOD;
    }

    return dp[i][rem]=sum%MOD;
}

void solve() {
    int n, r;
    cin >> n >> r;

    
    if(n<r) cout << -1 << endl;
    else{
        vector<vector<ll>> dp(r+1,vector<ll>(n+1,-1));
        cout<<recr(dp,1,n,r,r)<<endl;
    }
}

int main() {
    fastio;
    solve();
    return 0;
}