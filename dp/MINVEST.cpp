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
    ll p,y;
    cin >> p >> y;
    ll nb;
    cin>>nb;
    vector<ll> bondcost(nb),boundint(nb);
    rep(i,0,nb){
        ll cost,it;
        cin>>cost>>it;
        bondcost[i]=cost/1000l;
        boundint[i]=it;
    }
  
    for(int year=0;year<y;year++){
        ll curp=p/1000l;
        vector<ll> dp(curp + 1, 0);
        for(int bond=0;bond<nb;bond++){
            for(ll amount=bondcost[bond];amount<=curp;amount++){
                if(amount-bondcost[bond]< 0) continue;
                dp[amount]=max(dp[amount],
                    dp[amount-bondcost[bond]]+boundint[bond]);
            }
        }
        p+=dp[curp];
    }
    cout<<p<<endl;

}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}