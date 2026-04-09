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



void solve(int bud,int ptn) {
    // cost ,fun
    vector<int> cost(ptn),fun(ptn);
 
    rep(i,0,ptn){
        int x,y;
        cin>>x>>y;
        cost[i]=x;
        fun[i]=y;
    }  

    vector<int> dp(bud+1,0);
    /*
    dry run this if not able to understand the code
    summary->
    using a 1d array in place of 2d and moving from right to left 
    making sure to take the max fun for each budget starting from index 0 
    
    */
    for(int i=0;i<ptn;i++){
        for(int j=bud;j>=cost[i];j--){
            dp[j]=max(dp[j],dp[j-cost[i]]+fun[i]);
        }
    }
    int maxfun=dp[bud];
    int i;
    for( i=0;i<bud;i++){
        if(dp[i] == maxfun) break;
    }
    cout<< i << " " << maxfun <<endl;




    
  
}

int main() {
    fastio;
    int b,p;
    while (cin>>b>>p && (b!=0 && p!=0)) solve(b,p);
    return 0;
}