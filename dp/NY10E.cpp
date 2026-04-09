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

vector<vector<ll>> dp(65,vector<ll>(11,-1));


void solve() {
    int t,n;
    cin >> t >> n ;

    cout << t << " " << dp[n][10] << endl;

}

int main() {
    fastio;
    int t = 1;
    cin >> t;


    for(int col=0;col<=9;col++){
        dp[1][col]=1ll;
    }
    ll ts=10ll;
    dp[1][10]=ts;

    for(int r=2;r<=64;r++){
        ll sum=0;
        for(int c=0;c<=9;c++){
            ts-=(c-1>=0?dp[r-1][c-1]:0);
            dp[r][c]=ts;
            sum+=dp[r][c];
        }
        ts=sum;
        dp[r][10]=ts;
    }

    while (t--) solve();
    return 0;
}