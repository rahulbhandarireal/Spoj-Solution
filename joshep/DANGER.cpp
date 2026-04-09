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
   if(k>n) return (jos( n-1, k) + k ) % n;
   int cnt=n/k;
   int res=jos(n-cnt,k);
   res-= n%k;
   if(res<0) res+=n;
   else
   res+=(res)/(k-1);
   return res;
}

void solve() {
    string s;
    while(cin>>s && (s != "00e0")){
        int x,y,z;
        x=s[0] - '0';
        y=s[1] - '0';
        z=s[3] - '0';
        int no=x*10 + y;
        while(z--){
            no=no*10;
        }
        cout<<jos(no,1)+1<<endl;

    }
    

}

int main() {
    fastio;
    solve();
    return 0;
}