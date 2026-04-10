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

string sol(unordered_map<int,int>& homo,unordered_set<int>& hetro,string s,int n ){
    char ch=s[0];
    if(ch == 'i'){
        // insert 
        if(hetro.count(n)){
            hetro.erase(n);
            homo[n]=2;
        }else if(homo.count(n)){
            homo[n]++;
        }else{
            hetro.insert(n);
        }
    }else{
        // delete 
        if(hetro.count(n)){
            hetro.erase(n);
        }else if(homo.count(n)){
            int val=homo[n];
            if(val == 2){
                homo.erase(n);
                hetro.insert(n);
            }else{
                homo[val]--;
            }
        }

    }

    int hetsize=hetro.size();
    int homosize=homo.size();
    if(hetsize+homosize >=2 && homosize>=1){
        return "both";
    }else if(homosize <=1 && homosize+hetsize>=2){
        return "hetero";
    }else if(hetsize<=2 && homosize>=1){
        return "homo";
    }else{
        return "neither";
    }
}

void solve() {
    int n;
    cin >> n;
    unordered_map<int,int> homo;
    unordered_set<int> hetro;
    rep(i,0,n){
        string op;
        cin>>op;
        int x;
        cin>>x;
        cout<<sol(homo,hetro,op,x)<<"\n";

    }

}

int main() {
    fastio;
    solve();
    return 0;
}