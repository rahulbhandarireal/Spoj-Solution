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


// face = true = right

bool isvalid(int i,int j,int r,int c){
    return i>=0 && i<r && j>=0 && j<c;
}

/*
no need to maintain a visited table as path will not be reused;

*/
int recr(vector<vector<char>>& gd,vector<vector<int>>& dp
    ,int i,int j,int r,int c,bool face){



        if(dp[i][j] != -1) return dp[i][j];

        int op1=0,op2=0;


        if(face){
            // right -> 
            int ni,nj;
            //right side 
            ni=i;
            nj=j+1;
            if(isvalid(ni,nj,r,c)){

                if(gd[ni][nj] == 'T' ){
                    op1=1+recr(gd,dp,ni,nj,r,c,face);
                }else if(gd[ni][nj] == '0'){
                    op1=recr(gd,dp,ni,nj,r,c,face);
                }

            }

        }else{
            //left ->

             int ni,nj;
            //left side 
            ni=i;
            nj=j-1;
            if(isvalid(ni,nj,r,c)){

                if(gd[ni][nj] == 'T' ){
                    op1=1+recr(gd,dp,ni,nj,r,c,face);
                }else if(gd[ni][nj] == '0'){
                    op1=recr(gd,dp,ni,nj,r,c,face);
                }

            }

        }

          //down side 
           int ni=i+1;
           int nj=j;
              if(isvalid(ni,nj,r,c)){

                if(gd[ni][nj] == 'T' ){
                    op2=1+recr(gd,dp,ni,nj,r,c,!face);
                }else if(gd[ni][nj] == '0'){
                    op2=recr(gd,dp,ni,nj,r,c,!face);
                }

            }


            return dp[i][j]=max(op1,op2);

}

void solve() {
    int r,c;
    cin >> r >> c;

    vector<vector<char>> gd(r,vector<char>(c));
    vector<vector<int>> dp(r,vector<int>(c,-1));

    rep(i,0,r){
        rep(j,0,c){
            cin>>gd[i][j];
        }
    }

    if(gd[0][0] == 'T'){
        cout<<1+recr(gd,dp,0,0,r,c,true)<<endl;
    }else if(gd[0][0] == '0'){
        cout<<recr(gd,dp,0,0,r,c,true)<<endl;
    }else if(gd[0][0]=='#'){
        cout<<0<<endl;
    }

    





}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}