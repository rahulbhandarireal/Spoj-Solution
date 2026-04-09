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

int recr(string& s,vector<vector<int>>& dp,int n,int i,int j){

    if( i >= j ) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;

    if(s[i] != s[j]){
        op1=1+recr(s,dp,n,i+1,j);
        op2=1+recr(s,dp,n,i,j-1);
    }else{
        op3=recr(s,dp,n,i+1,j-1);
    }

    return dp[i][j]=min(op1,min(op2,op3));
}

void solve() {
    string n;
    cin >> n ;

    int s=n.size();

    vector<vector<int>> dp(s+1,vector<int>(s+1,-1));

    cout<<recr(n,dp,s,0,s-1)<<endl;

}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}