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


bool isvalid(int i,int j,int r,int c){
    return (i>=0 && i<r && j>=0 && j<c);
}

vector<pair<int,int>> directions ={{1,0},{-1,0},{0,1},{0,-1}};

int dfs(vector<vector<int>>& grid,int i,int j
    ,int r,int c){

        int val=1;
         grid[i][j]=0;
        for(auto [k,l] : directions){
            int ni=k+i;
            int nj=l+j;
            if(isvalid(ni,nj,r,c) && grid[ni][nj] == 1){
              val=val+dfs(grid,ni,nj,r,c);
             
            }

        }
        return val;






}

void solve() {
    int r, c;
    while (cin >> r >> c && r != 0 && c != 0) {

        vector<vector<int>> grid(r, vector<int>(c));
        map<int, int> res;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> grid[i][j];
            }
        }
        int slick=0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    int sz = dfs(grid, i, j, r, c);
                    res[sz]++;
                    slick++;
                }
            }
        }
        cout<<slick<<endl;
        for (auto &x : res) {
            cout << x.first << " " << x.second << "\n";
        }
    }
}


int main() {
    fastio;
    solve();
    return 0;
}