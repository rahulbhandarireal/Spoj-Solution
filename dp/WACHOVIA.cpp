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


/*
a 2d dp problem maintaing the remaning weight and index
simple option of take if rm-a[i]>=0 and not take


*/

ll recr(vector<pair<ll,ll>>& ar,vector<vector<ll>>& dp,int i,ll rw){
    int size=ar.size();
    if(i == size || rw<=0 ) return 0ll;

    if(dp[i][rw] != -1) return dp[i][rw];

    ll v1=0,v2=0;

    //take 
    if(rw - ar[i].ff >=0)
    v1=ar[i].ss + recr(ar,dp,i+1,rw-ar[i].ff);

    //not take
    v2=recr(ar,dp,i+1,rw);

    return dp[i][rw]=max(v1,v2);

}

void solve() {
    int k,n;
    cin >> k >> n;
    vector<pair<ll,ll>> ar(n);
    ll tw=0;
    rep(i,0,n){
        int w,v;
        cin>>w>>v;
        ar[i]={w,v};
        tw+=w;
    }

    vector<vector<ll>> dp(n+1,vector<ll>(k+1,-1));

    cout << "Hey stupid robber, you can get " << recr(ar,dp,0,k) <<"." << endl;

}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}