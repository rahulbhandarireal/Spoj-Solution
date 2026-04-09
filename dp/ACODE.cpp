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

int recr(string& s,int i,vector<int>& dp){
    int n=s.size();
    // reached end its valid conversion return 1
    if(i >= n) return 1;
    // any char as 0 is invalid combination return 0
    if(s[i] == '0') return 0;

    if(dp[i] != -1) return dp[i];
    int op1=0,op2=0;

    int ch1=s[i]-'0';
    // move one by one
    op1=recr(s,i+1,dp);
    if(i+1<n){
        // if i and i +1 can make  a valid char make it else leave it
     int ch2=s[i+1]-'0';
     int rem=ch1*10+ch2;
     if(rem <=26){
        op2=recr(s,i+2,dp);
     }
    }

    // use dp to store total way possible from i index
    return   dp[i] = op1+op2;

}

void solve(string  n) {

    int size=n.size();

    vector<int> dp(size+1,-1);

    cout<<recr(n,0,dp)<<endl;


}

int main() {
    fastio;
    string t;
    while (cin>>t && t != "0" ) solve(t);
    return 0;
}