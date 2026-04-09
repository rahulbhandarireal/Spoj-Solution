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

vector<int> dp(1e3 +1 ,-1);


void solve() {
    int n;
    cin >> n;
    cout<<dp[n]<<endl;

}

/*
   1 -> 1 = 1 
   2 -> 2 = 1 1
   3 -> 3 = 1 1 1   
   4 -> 1 = 3 + 1 or  2*2
   5 -> 2 =  4 + 1
   6 -> 3 =  5 + 1 or 4+2 not possible
   7 -> 4 =  6 + 1 (4) or   
   8 -> 2
   9 -> 1
   10 -> 2 dp[i-1]+1 or sqrt(i)*sqrt(i) 
   11 -> 3
   12 -> 3       (4*3)  = (2*sqrt(3)) 
   13 -> 4
   14 -> 3

   it shows that d[i*i]=1 for 1=1 to i*i<1e3 +1
   for others dp[i] = min(dp[1..j-1]+dp[1..k-1]) for j,k<i-1 if j+k = i;
*/

int main() {
    fastio;
    int t = 1;
    cin >> t;
    dp[1]=1;
    dp[0]=0;

    for(int i=1;i*i<1e3+1;i++){
        dp[i*i]=1;
    }


    for(int i=1;i<1e3 + 1;i++){
        int mini=INT_MAX;
        if(dp[i] != -1) continue;
        for(int j=1;j<i;j++){
            for(int k=j;k<i;k++){
                if(j+k == i){
                    mini=min(mini,dp[j]+dp[k]);
                }
            }
        }
        dp[i]=mini;
    }


    while (t--) solve();
    return 0;
}