#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

struct Order {
    ll s, e, p;
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<Order> orders(n);
    for (int i = 0; i < n; i++) {
        ll start, duration, price;
        cin >> start >> duration >> price;
        // The problem gives duration; we need the end time (start + duration)
        orders[i] = {start, start + duration, price};
    }

    // 1. Sort by end time: This is the foundation of the DP approach
    sort(orders.begin(), orders.end(), [](const Order& a, const Order& b) {
        if (a.e != b.e) return a.e < b.e;
        return a.s < b.s;
    });

    // 2. Extract end times into a separate vector for binary search
    vector<ll> endTimes;
    for (const auto& o : orders) {
        endTimes.push_back(o.e);
    }

    // 3. dp[i] = maximum profit possible using a subset of the first i orders
    // We use n+1 to have dp[0] = 0 as a base case
    vector<ll> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        // Choice 1: Exclude the current order (take the best result from i-1)
        ll exclude = dp[i - 1];

        // Choice 2: Include the current order
        ll include = orders[i - 1].p;

        // Use binary search (upper_bound) to find the last order 
        // that finishes before or exactly when the current order starts.
        // upper_bound finds the first element > orders[i-1].s
        auto it = upper_bound(endTimes.begin(), endTimes.begin() + (i - 1), orders[i - 1].s);
        
        if (it != endTimes.begin()) {
            // Move back one step to get the last compatible index
            int lastCompatibleIdx = distance(endTimes.begin(), prev(it));
            include += dp[lastCompatibleIdx + 1]; // +1 because dp is 1-indexed
        }

        // The state dp[i] is the maximum of our two choices
        dp[i] = max(include, exclude);
    }

    // The answer is the max profit considering all n orders
    cout << dp[n] << "\n";
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}