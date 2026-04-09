#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

// We'll use a boolean array since we are filling it iteratively
bool canWin[1000001];

void solve() {
    int k, l, m;
    cin >> k >> l >> m;

    vector<int> ar(m);
    int max_n = 0;
    for(int i = 0; i < m; i++) {
        cin >> ar[i];
        max_n = max(max_n, ar[i]);
    }

    // Base Case
    canWin[0] = false; 

    for (int i = 1; i <= max_n; i++) {
        // Current player wins if they can make a move to a state where 
        // the opponent (the player at i-1, i-k, or i-l) LOSES.
        
        bool move1 = !canWin[i - 1];
        bool moveK = (i >= k) ? !canWin[i - k] : false;
        bool moveL = (i >= l) ? !canWin[i - l] : false;

        if (move1 || moveK || moveL) {
            canWin[i] = true; // Found a way to force opponent to lose
        } else {
            canWin[i] = false; // All moves lead to opponent winning
        }
    }

    string s = "";
    for (int i = 0; i < m; i++) {
        if (canWin[ar[i]]) s += 'A';
        else s += 'B';
    }
    cout << s << endl;
}

int main() {
    fastio;
    solve();
    return 0;
}