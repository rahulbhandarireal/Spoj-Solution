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
    int n;
    cin >> n ;
    int coin;
    cin>>coin;
    vector<int> value(coin);
    vin(value,coin);
    vector<bool> dp(n+1,false);
    dp[0]=true;
    vector<int> bundel;
    int sum=0;
    for(auto x : value){
        sum+=x;
        bundel.push_back(sum);
    }
    
    for(auto bun : bundel){
        for(int j=bun;j<=n;j++){
            if(dp[j - bun]){
                dp[j]=true;
            }
        }
        if(dp[ n]) break;
    }
    if(dp[n]) YES
    else NO
}
/*

 25 -  5,3,2
   b1 = 5 = 5
   b2 = 5,3 = 8
   b3 = 5,3,2 = 10

   now i need to make sum 25 using this bundle and everytime i pick a bundle the constraint is maintained


*/

int main() {
    fastio;
    solve();
    return 0;
}