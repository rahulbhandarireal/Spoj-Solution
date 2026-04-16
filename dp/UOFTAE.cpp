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

ll MOD=1e9 +7;
ll dp[201][201];
ll recr(vector<pair<int,int>>fox , int i,int rem){
    if(i == fox.size()-1){
        if(rem >= fox[i].ff && rem < fox[i].ss) return 1ll;
        else return 0ll;
    }
    if(rem == 0) return 0ll;
    if(dp[i][rem] != -1) return dp[i][rem];

    ll ans=0;
    for(int start=fox[i].ff ; start<=rem && start<=fox[i].ss;start++){
        ans=(ans+recr(fox,i+1,rem-start))%MOD;
    }

    return dp[i][rem]=ans%MOD;

}

void solve_optimized() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> fox(n);
    rep(i,0,n){
        int s,e;
        cin>>s>>e;
        fox[i]={s,e};
    }
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    for(int i=0;i<n;i++){
        int low=fox[i].ff;
        int end=fox[i].ss;
        vector<int> next_dp(m+1,0);
    for(int j=0;j<=m;j++){
        if(dp[j] <= 0) continue;
        for(int k=low;k<=end;k++){
            if(k+j <=m)
            next_dp[j+k]=(dp[j]+next_dp[j+k])%MOD;
            else
            break;
        }
    }
    dp=next_dp;
}
    cout << dp[m] << "\n";
}


void solve() {
    memset(dp,-1,sizeof(dp));
    int n, m;
    cin >> n >> m;
    //          s,e
    vector<pair<int,int>> fox(n);
    rep(i,0,n){
        int s,e;
        cin>>s>>e;
        fox[i]={s,e};
    }

    cout<<recr(fox,0,m)<<"\n";



}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve_optimized();
    return 0;
}