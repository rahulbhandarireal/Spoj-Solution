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

unordered_map<ll,ll> mp;
ll dp[1000000];

ll solve(ll n) {

    // if checking !=-1 can cause segmentation fault and all index < 1e6 are filled
    if(n < 1e6 ) return dp[n];

    if(mp.count(n)) return mp[n];


    return mp[n]=max(n,solve(n/2)+solve(n/3)+solve(n/4));
}

int main() {
    fastio;
    ll t = 1;
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
      for(ll i = 4;i<1e6;i++){
        dp[i]=max(i,dp[i/2]+dp[i/4]+dp[i/3]);
    }

    while(cin>>t) {
        cout<<solve(t)<<endl;
    }
    return 0;
}