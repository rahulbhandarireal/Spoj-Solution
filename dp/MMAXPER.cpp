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


// PREVIOUS H IS IMPORTANT FOR CALCULATION
int recr(vector<pair<int,int>>& ar,int i,int h,vector<vector<int>>& dp){
    if(i == ar.size()) return 0;
    if(dp[i][h] != -1) return dp[i][h];
    int op1=0,op2=0;
    int h1=ar[i].ff;
    int w1=ar[i].ss;

    op1=abs(h1-h)+w1+recr(ar,i+1,h1,dp);
    int h2=ar[i].ss;
    int w2=ar[i].ff;
    op2=abs(h2-h)+w2+recr(ar,i+1,h2,dp);
    return dp[i][h]=max(op1,op2);
}

void solve() {
    int n;
    cin >> n ;
    vector<pair<int,int>> ar(n);
    vector<vector<int>> dp(1001,vector<int>(1001,-1));
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        ar[i]={x,y};
    }

    cout<<  max(ar[0].ss+recr(ar,1,ar[0].ff,dp),ar[0].ff+recr(ar,1,ar[0].ss,dp));



}

int main() {
    fastio;
    solve();
    return 0;
}