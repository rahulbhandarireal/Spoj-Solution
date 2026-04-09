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




void solve() {
    int r, c;
    cin >> r >> c;

    vector<vector<char>> grid(r, vector<char>(c));
    vector<vector<int>> res(r, vector<int>(c, -1));

    queue<pair<int,int>> q;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> grid[i][j];
            if(grid[i][j] == '1'){
                res[i][j] = 0;
                q.push({i, j});   // multi-source
            }
        }
    }

    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();

        for(auto [dx, dy] : directions){
            int ni = i + dx;
            int nj = j + dy;

            if(ni >= 0 && ni < r && nj >= 0 && nj < c && res[ni][nj] == -1){
                res[ni][nj] = res[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}


int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}