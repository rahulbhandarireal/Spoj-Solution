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


int jos(int n,int k){
   if(n == 1) return 0;
   if(k == 1) return n-1;
    return (jos( n-1, k+1) + k ) % n;
}

void solve() {
    int n;
    cin>>n;
    cout<<jos(n,1)+1<<endl;
}

int main() {
    fastio;
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}