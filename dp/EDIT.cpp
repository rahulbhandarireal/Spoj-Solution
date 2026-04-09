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


// islower function returns a int value can't be compared with boolean
bool issmall(char ch){
    return ch>='a' && ch<='z';
}

int countop(bool curLower,int n,string& s){
    int op=0;
    int i=0;

    while(i<n){
        char ch = s[i];
        if(curLower != issmall(ch)){
            op++;
        }
        curLower=!curLower;
        i++;
    }
    return op;
}


void solve(string s) {
    /*
    Only two solution are possible LULU or ULUL
    just count the minimum operations for both the solution
    */

    int i=0;
    int n=s.size();

    int op1=countop(true,n,s);
    int op2=countop(false,n,s);

    cout<<min(op1,op2)<<endl;




    

}

int main() {
    fastio;
    string s;
    while (cin>>s) solve(s);
    return 0;
}