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


    vector<vector<ll>> dp;

ll recr(vector<ll>& ar,int i,int j,ll age){

    if(i>j) return 0ll;

    if(dp[i][age] != -1) return dp[i][age];

    ll op1=0ll,op2=0ll;

    //take from front
    op1=recr(ar,i+1,j,age+1) + ar[i]*age;

    op2=recr(ar,i,j-1,age+1)+ ar[j]*age;


    return dp[i][age]=max(op1,op2);


}

void solve() {
    int n ;
    cin >> n ;
    vector<ll> ar(n);
    vin(ar,n);

    dp.resize(n + 1, vector<ll>(n + 1, -1));


    cout<<recr(ar,0,n-1,1)<<endl;


}

int main() {
    fastio;
    solve();
    return 0;
}