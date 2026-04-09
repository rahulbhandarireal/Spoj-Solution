#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    int target_oxy, target_nitro, n;
    if (!(cin >> target_oxy >> target_nitro)) return;
    cin >> n;

    vector<vector<int>> dp(target_oxy + 1, vector<int>(target_nitro + 1, INF));
    dp[0][0] = 0;

    for (int k = 0; k < n; ++k) {
        int co, cn, cw;
        cin >> co >> cn >> cw;
        for(int i=target_oxy;i>=0;i--){
              int pi=max(0,i-co);
            for(int j=target_nitro;j>=0;j--){
                int pj=max(0,j-cn);
                dp[i][j]=min(dp[i][j],dp[pi][pj]+cw);
            }
        }
    }
    cout << dp[target_oxy][target_nitro] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c;
    if (!(cin >> c)) return 0;
    while (c--) {
        solve();
    }
    return 0;
}