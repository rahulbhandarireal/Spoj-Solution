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
vector<pair<int,int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}}; // Up, Right, Down, Left
vector<char> dir_labels = {'U', 'R', 'D', 'L'};
bool isvalid(int i,int j,int r,int c){
    return (i>=0 && i < r && j>=0 && j<c);
}

void solve() {
    int w,h;
    cin >> w >> h;
    
    vector<vector<char>> grid(h,vector<char>(w));
    vector<pair<int,int>> se;
    
    rep(i,0,h){
        string r;
        cin>>r;
        rep(j,0,w){
            grid[i][j]=r[j];
            if(r[j] == 'C'){
                se.push_back({i,j});
            }
        }
    }
    
    pair<int,int> st=se[0];
    pair<int,int> ed=se[1];
    
    // Distance matrix to track visited and distance
     
   
    for(int i=0;i<4;i++){
        vector<vector<pair<char,int>>> dist(h,vector<pair<char,int>>(w, {'t',-1}));
        int ni=st.ff+directions[i].ff;
        int nj=st.ss+directions[i].ss;
        if(isvalid(ni,nj,h,w) && grid[ni][nj] != '*'){
            dist[ni][nj]={dir_labels[i],0};
            bfs()
        }
    }


}

int main() {
    fastio;
   solve();
    return 0;
}