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

ll myrecr(int i,vector<ll>& ar,vector<ll>& dp){
    int n=ar.size();

    if(i >= n ) return 0;

    if(dp[i] != -1 ) return dp[i];
    ll op1=0ll,op2=0ll,op3=0ll; 

    //take one
    op1=ar[i]+myrecr(i+2,ar,dp);
    if(i+1<n)
    op2=ar[i]+ar[i+1]+myrecr(i+4,ar,dp);
    if(i+2<n)
    op3=ar[i]+ar[i+1]+ar[i+2]+myrecr(i+6,ar,dp);


    return dp[i]=max(op1,max(op2,op3));
}

void solve() {
    int n;
    cin >> n ;
    vector<ll> ar(n);
    vin(ar,n);
    
    vector<ll> dp(n+1,-1);

    cout<<myrecr(0,ar,dp)<<endl;

    // rep(i,0,n+1){
    //     cout<<"index"<<i<<":"<<dp[i]<<endl;
    // }
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}