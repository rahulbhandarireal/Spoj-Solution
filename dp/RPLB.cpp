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

void solve(int s) {
    int n, limit;
    cin >> n >> limit;

    vector<int> bu(n);
    vin(bu,n);
    vector<vector<ll>> dp(n,vector<ll>(limit+1,0));

    rep(i,0,n){
        ll fw=bu[i];
        repr(j,limit,0){
                ll toadd=(i-2 < 0 || j-fw<0)?0:dp[i-2][j-fw];
                ll tocom=(i-1>=0)?dp[i-1][j]:0;
                if(fw+toadd <= j) 
                dp[i][j]=max(tocom,fw+toadd);
                else
                dp[i][j]=tocom;
        }
    }
    
    ll ans=0;
    for(int i=0;i<=limit;i++){
        ans=max(ans,dp[n-1][i]);
    }

    cout<<"Scenario #"<<s<<": "<<ans<<endl;


}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    int i=1;
    while (i<=t) solve(i++);
    return 0;
}