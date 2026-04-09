#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

     vector<pair<int,int>> directions={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1}};

    bool isvalid(int i,int j,int r,int c){
        return (i>=0 && i < r && j>=0 && j<c );
    }

    int dfs(int i,int j, vector<vector<int>>& grid,int code,int r,int c, vector<vector<int>>& dp){
        //bc
        if(code > (int)'Z') return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        int cur=0;
        for(int k=0;k<8;k++){
            int ni=i+directions[k].first;
            int nj=j+directions[k].second;
            if( !isvalid(ni,nj,r,c) ) continue;
            if(grid[ni][nj] == code){
                grid[ni][nj]=-1;
                cur=max(cur,1+ dfs(ni,nj,grid,code+1,r,c,dp));
                grid[ni][nj]=code;
            }
        }
       return dp[i][j]=cur;
    }
    
int main(){
    int row,col;
    cin>>row>>col;
    int seq=1;

    while(row != 0 && col != 0){
        vector<vector<int>> grid(row,vector<int>(col));
        vector<pair<int,int>> multisource;
        //B 66
        // (i,j)-> i+1,j | i,j+1 | i-1,j | i,j-1 |
        // i+1,j+1 | i-1,j+1 | i-1,j-1 | i+1,j-1

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                char ch;
                cin>>ch;
                if(ch == 'A')
                multisource.push_back({i,j});
                grid[i][j]=(int)ch;
            }
        }

        int maxi=INT_MIN;
    for(int i=0;i<multisource.size();i++){
            int ni=multisource[i].first;
            int nj=multisource[i].second;
            vector<vector<int>> dp(row,vector<int>(col,-1));
        maxi=max(maxi,dfs(ni,nj,grid,66,row,col,dp));
        }
        cout<<"Case "<<seq<<": "<<1+maxi<<endl;
        cin>>row>>col;
    }
    return 0;
}