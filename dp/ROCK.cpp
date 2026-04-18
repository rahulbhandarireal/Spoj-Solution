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

//ll dp[201][201][201];

// ll recr(string& s,int i,int no,int nz){
//     if(s.size() == i) {
//         if(no>nz) return no+nz;
//         else return 0;
//     }
//     if(s[i] == '1') no++;
//     else nz++;
//     if(dp[i][no][nz] != -1) return dp[i][no][nz];
//     ll take=INT_MIN,nottake=INT_MIN,nottake2=INT_MIN;
//     if(no>nz){
//         take=no+nz+recr(s,i+1,0,0);
//     }
//     nottake=recr(s,i+1,no,nz);
//     nottake2=recr(s,i+1,0,0);
//      return dp[i][no][nz]= max(take,max(nottake,nottake2));
// }


ll recrbtup(){
     ll n;
    cin >> n ;
    string s;
    cin>>s;

    vector<ll> dp(n,0);
    ll ones=0;
    ll antmax = 0;
    for(ll i=0;i<n;i++){
        ones=0;
        for(ll j=i;j>=0;j--){
            if(s[j] == '1') ones++;
            else ones--;
             int val=(j-1>=0)?dp[j-1]:0;
            if( ones > 0 ){
                antmax=max(antmax,i-j+1+val);
            }
        }
        dp[i]=antmax;
    }
  
    cout<<dp[n-1]<<"\n";






}


// void solve() {
//     memset(dp,-1,sizeof(dp));
//     int n;
//     cin >> n ;
//     string s;
//     cin>>s;
//     cout<<recr(s,0,0,0)<<"\n";


// }

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) recrbtup();
    return 0;
}