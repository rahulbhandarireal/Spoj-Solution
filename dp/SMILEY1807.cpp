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


int returnidx(int n){
    if(n == 1) return 0;
    if(n == 8) return 1;
    if(n == 0) return 2;
    else return 3;
}

void solve() {
    string n;
    cin >> n ;
    int sz=n.size();
    vector<vector<int>> dp(sz,vector<int>(4,0));

    int i=0;
    while( i<sz && n[i] != '1') i++;
    // 1 - 8 - 0 - 7
    if(i == sz ){
        cout<<0<<"\n";
        return;
    }
    dp[i][0]=1;
    i++;
    int ans=0;
    for(i;i<sz;i++){
        int no=n[i]-'0';
        int idx=returnidx(no);
        rep(j,0,4){
            if(j == idx){
                int val=dp[i-1][j];
                int val2=(j==0)?0:dp[i-1][j-1];
                if(val ==0 && val2 == 0){
                    continue;
                }
                dp[i][j]=max(val,val2)+1;
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
        ans=max(ans,dp[i][3]);
    }
    cout<<ans<<"\n";


}

int main() {
    fastio;
    solve();
    return 0;
}