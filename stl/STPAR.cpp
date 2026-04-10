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

void solve(int t) {
    vector<int> ar(t);
    vin(ar,t);
    stack<int> st;
    vector<int> ans;
    rep(i,0,t){
        while(!st.empty() && ar[i] > st.top()){
            ans.push_back(st.top());
                st.pop();        
        }
            st.push(ar[i]);

    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    bool isorder=true;
    rep(i,1,t+1){
        if(i != ans[i-1]) {
            isorder=false;
            break;
        }
    }
    if(isorder) cout<<"yes"<<"\n";
    else cout<<"no"<<"\n";
}

int main() {
    fastio;
    int t = 1;
    while (cin>>t && t!=0) solve(t);
    return 0;
}