#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[601][601];

void solve() {
    int W, H, N;
    cin >> W >> H >> N;

    // Initialize DP table with maximum possible waste (the area itself)
    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= H; j++) {
            dp[i][j] = i * j;
        }
    }

    // Mark desired plates as having 0 waste
    for (int i = 0; i < N; i++) {
        int w, h;
        cin >> w >> h;
        if (w <= W && h <= H) {
            dp[w][h] = 0;
        }
    }

    // Fill DP table
    for (int w = 1; w <= W; w++) {
        for (int h = 1; h <= H; h++) {
            // Try all possible vertical cuts
            for (int i = 1; i <= w / 2; i++) {
                dp[w][h] = min(dp[w][h], dp[i][h] + dp[w - i][h]);
            }
            // Try all possible horizontal cuts
            for (int j = 1; j <= h / 2; j++) {
                dp[w][h] = min(dp[w][h], dp[w][j] + dp[w][h - j]);
            }
        }
    }

    cout << dp[W][H] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}