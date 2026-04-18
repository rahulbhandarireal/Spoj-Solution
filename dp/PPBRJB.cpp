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

int MAX_COUNT=1e7;
vector<int> primeno(MAX_COUNT,0);

void findprime(){
    vector<bool> isprime(MAX_COUNT,true);
    isprime[0]=false;
    isprime[1]=false;

    for(int j=4;j<MAX_COUNT;j+=2){
        isprime[j]=false;
    }
    for(int k=3;k*k<MAX_COUNT;k++){
        if( !isprime[k] ) continue;
        for(int l=k*k;l<MAX_COUNT;l+=2*k){
            isprime[l]=false;
        }
    }

    int count=0;
    for(int i=1;i<MAX_COUNT;i++){
        if(isprime[i]) count++;
        primeno[i]=count;
    }
}




void solve() {
    int n;
    cin >> n ;
    vector<ll>dp(n+1,0);
    dp[0]=1;

    for(int i=1;i<=n;i++){
        ll i1=(i-4>=0)?dp[i-4]:0;
        ll i2=(i-1>=0)?dp[i-1]:0;
        dp[i]=i1+i2;
    }

    int ans=dp[n];
    cout<<primeno[ans]<<"\n";
}

int main() {
    findprime();
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}