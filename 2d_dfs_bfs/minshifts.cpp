#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> directions = {
    {-1,0}, {-1,1}, {0,1},
    {1,1}, {1,0}, {1,-1},
    {0,-1}, {-1,-1}
};

bool isvalid(int i,int j,int r,int c){
    return i>=0 && i<r && j>=0 && j<c;
}

void findmaxi(vector<vector<char>>& vp, int i, int j,
              int r, int c, char cur, int val, int &gmax,vector<vector<int>>& dp) {

    gmax = max(gmax, val);   // update best so far

    if(dp[i][j] != -1) {
        gmax=max(gmax,dp[i][j]);
        return;
    }

    cur++;                   // next expected character
    if (cur > 'Z') return;   // nothing beyond Z

    for (auto [dx, dy] : directions) {
        int ni = i + dx;
        int nj = j + dy;
        if (isvalid(ni, nj, r, c) && vp[ni][nj] == cur) {
            findmaxi(vp, ni, nj, r, c, cur, val + 1, gmax,dp);
        }
    }
    dp[i][j]=gmax;
}

int main() {

   int h,w;
   int counter=1;
    cin >> h >> w;
    do {
        vector<vector<int>> dp(h, vector<int>(w,-1));
        vector<vector<char>> vp(h, vector<char>(w));
        vector<pair<int,int>> ms;   // positions of 'A'
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char ch;
                cin >> ch;
                vp[i][j] = ch;
                if (ch == 'A') {
                    ms.push_back({i, j});
                }
            }
        }

        int best = 0;   // longest path length

        for (auto [x, y] : ms) {
            int gmax = 1;   // at least the 'A' itself
            findmaxi(vp, x, y, h, w, 'A', 1, gmax,dp);
            best = max(best, gmax);
        }

        cout << "Case " << counter << ": " << best << endl;
        counter++;
         cin >> h >> w;
    }while(h!=0 && w!=0 );

    return 0;
}
