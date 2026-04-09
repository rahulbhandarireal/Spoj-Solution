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
maintaing a 2dp array for both the station
for ith index  there are two options
1-> same station dp[i-1]
2-> different station dp[i-1] + same station s[i-1]
and increasing i till dp[i] < l 
*/

void solve() {
    int n, l;
    cin >> n >> l;

    vector<int> a(n);
    vector<int> b(n);
    vector<ll> adp(n,INT_MAX);
    vector<ll> bdp(n,INT_MAX);

    vin(a, n);
    vin(b, n);

    adp[0] = a[0];
    bdp[0] = b[0];

    for (int i = 1; i < n; i++) {
        ll same_a = adp[i-1] + a[i];
        ll change_a = bdp[i-1] + a[i-1] + a[i];
        adp[i] = min(same_a, change_a);
        
        int same_b = bdp[i-1] + b[i];
        int change_b = adp[i-1] + b[i-1] + b[i];
        bdp[i] = min(same_b, change_b);
        
        if (adp[i] > l && bdp[i] > l) {
            // breaking the loop as dp[i] > l
            for (int j = i; j < n; j++) {
                adp[j] = l + 1;
                bdp[j] = l + 1;
            }
            break;
        }
    }
    
    int max_index = 0;
    int no=0;
    for (int i = 0; i < n; i++) {
        if (adp[i] <= l || bdp[i] <= l) {
            max_index = i + 1;  
            no=min(adp[i],bdp[i]);
        } else {
            break;
        }
    }
    
    cout << max_index << " " << no  << "\n";
}

int main() {
    fastio;
    solve();
    return 0;
}