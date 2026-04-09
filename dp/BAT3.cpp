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
    int n, a;
    cin >> n >> a ;
    vector<int> ar(n);
    vin(ar,n);
    vector<int> dp(n,1);
    int ans=INT_MIN;
    rep(i,1,n){
        int maxi=1;
        rep(j,0,i){
            if(ar[j] > ar[i] || j==a)
            maxi=max(dp[j]+1,maxi);
        }
        dp[i]=maxi;
        ans=max(ans,maxi);
    }

    cout<<ans<<"\n";


}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}