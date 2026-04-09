#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> ar(n);
        for (auto &x : ar) cin >> x;

        
        ll high = *max_element(ar.begin(), ar.end());
        ll low = 1, ans = 0;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            long long student = 0;

            //one box can feed multiple student 
            //if it has enough candies
            for (int i = 0; i < n; i++) {
                student += ar[i] / mid;
            }

            if (student >= k) {
                ans = mid;     
                low = mid + 1;  
            } else {
                high = mid - 1; 
            }
        }

        cout << ans << endl;
    }

    return 0;
}
