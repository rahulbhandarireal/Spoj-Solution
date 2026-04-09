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
    int p,pm;
    cin >> p >> pm;
    ll tar=pm-p;
    int n;
    cin>>n;
    vector<ll> dp(tar+1,LLONG_MAX);
    vector<ll> coin(n),wi(n);
    rep(i,0,n){
        int c,w;
        cin>>c>>w;
        coin[i]=c;
        wi[i]=w;
    }
    dp[0]=0;

    for(int i=0;i<n;i++){
        for(int bud=1;bud<=tar;bud++){
            if(wi[i] <= bud ){
                int cw=bud-wi[i];
                if( cw<0  || dp[cw] == LLONG_MAX ) continue; 
                dp[bud]=min(dp[bud],coin[i]+dp[cw]);
            }
        }
    }
    if(dp[tar] == LLONG_MAX){
        cout<<"This is impossible."<<endl;
    }else{
        cout<<"The minimum amount of money in the piggy-bank is "<<dp[tar]<<"."<<endl;
    }

}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}