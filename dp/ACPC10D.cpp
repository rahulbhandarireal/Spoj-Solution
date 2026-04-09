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

void solve(int r,int k) {
   

    vector<vector<ll>> grid(r,vector<ll>(3));
    vector<vector<ll>> dp(r,vector<ll>(3,LLONG_MAX));

    rep(i,0,r){
        rep(j,0,3){
            cin>>grid[i][j];
        }
    }

    dp[0][1]=grid[0][1];
    dp[0][0]=LLONG_MAX;
    dp[0][2]=grid[0][1]+grid[0][2];

    rep(i,1,r){

        rep(j,0,3){

            if(j == 0 ){
                //two choices
                ll c1=LLONG_MAX,c2=LLONG_MAX;
                if(dp[i-1][j] != LLONG_MAX)
                c1=dp[i-1][j];

                c2=dp[i-1][j+1];
                dp[i][j]=min(c1,c2)+grid[i][j];
            }else if(j == 1){
                //4 choices
                ll c1=LLONG_MAX,c2=LLONG_MAX,c3=LLONG_MAX,c4=LLONG_MAX;
                if(dp[i-1][j-1] != LLONG_MAX)
                c1=dp[i-1][j-1];

                c2=dp[i][j-1];

                c3=dp[i-1][j];

                c4=dp[i-1][j+1];

                dp[i][j]=min(c1,min(c2,min(c3,c4)))+grid[i][j];

            }else if(j == 2){
                // 3 choice
                 ll c1=LLONG_MAX,c2=LLONG_MAX,c3=LLONG_MAX;
               
                 c1=dp[i-1][j];
                 c2=dp[i-1][j-1];
                 c3=dp[i][j-1];
                 dp[i][j]=min(c1,min(c2,c3))+grid[i][j];
            }
        }

    }

    cout<<k<<". "<<dp[r-1][1]<<endl;

}

int main() {
    fastio;
    int t = 1;
    int k=1;
   
    while (cin>>t && t!=0) {
        solve(t,k);
        k++;
    }
    return 0;
}