#include <bits/stdc++.h>
using namespace std;

struct Block {
    long long l, w, h;
};

// Memoization table: stores max height starting with block i as the base
long long memo[100]; 
vector<Block> all_orientations;

long long recr(int i) {
    if (memo[i] != -1) return memo[i];

    long long max_above = 0;
    // Try to place every other block 'j' on top of block 'i'
    for (int j = 0; j < all_orientations.size(); j++) {
        if (all_orientations[j].l < all_orientations[i].l && 
            all_orientations[j].w < all_orientations[i].w) {
            max_above = max(max_above, recr(j));
        }
    }

    return memo[i] = all_orientations[i].h + max_above;
}

void solve(int n) {
    all_orientations.clear();
    for (int i = 0; i < n; i++) {
        long long d[3];
        cin >> d[0] >> d[1] >> d[2];
        sort(d, d + 3); // d[0] <= d[1] <= d[2]

        // Create 3 orientations where L >= W
        all_orientations.push_back({d[2], d[1], d[0]});
        all_orientations.push_back({d[2], d[0], d[1]});
        all_orientations.push_back({d[1], d[0], d[2]});
    }

    memset(memo, -1, sizeof(memo));
    long long global_max = 0;

    // Any of the generated orientations can be the base of the tower
    for (int i = 0; i < all_orientations.size(); i++) {
        global_max = max(global_max, recr(i));
    }
    cout << global_max << "\n";
}

int main() {
    int n;
    while (cin >> n && n != 0) solve(n);
    return 0;
}