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

/*
2D DP as i,j are only changing state
*/


int recr(vector<int>& ar,vector<vector<int>>& dp,int i,int j){

    if(i>=j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int op1=0,op2=0;

    // choose left
    if( i+1 < ar.size()   && ar[i+1]>=ar[j]){
        op1=ar[i]+recr(ar,dp,i+2,j);
    }else{
        op1=ar[i]+recr(ar,dp,i+1,j-1);
    }


    //choose right
    if(  j-1>=0  && ar[i]>=ar[j-1]){
        op2=ar[j]+recr(ar,dp,i+1,j-1);
    }else{
        op2=ar[j]+recr(ar,dp,i,j-2);
    }

    return dp[i][j]=max(op1,op2);
}

void solve(int n,int g) {
    
    vector<int> ar(n);
    vin(ar,n);

    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    int sm=0;
    rep(i,0,n){
        sm+=ar[i];
    }

    int ans=recr(ar,dp,0,n-1);
    cout << "In game "<<g <<", the greedy strategy might lose by as many as "<<ans - (sm-ans)<<" points."<<endl;
}

int main() {
    fastio;
    int t ;
    int game=1;
    while (cin>>t && t!=0 ) solve(t,game++);
    return 0;
}