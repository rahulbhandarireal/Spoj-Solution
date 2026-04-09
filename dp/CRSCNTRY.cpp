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

int LCS(const vector<int>& A, const vector<int>& B) {
    int n = A.size(), m = B.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        fill(curr.begin(), curr.end(), 0);
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1])
                curr[j] = prev[j - 1] + 1;
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        swap(prev, curr);
    }
    return prev[m];
}

vector<int> readRoute(const string& line) {
    stringstream ss(line);
    vector<int> route;
    int x;
    while ( ss >> x && x != 0)
        route.push_back(x);
    return route;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d;
    cin >> d;
    cin.ignore();

    while (d--) {
        string line;

        getline(cin, line);
        vector<int> agnes = readRoute(line);

        int best = 0;

        while (true) {
            getline(cin, line);
            vector<int> tom = readRoute(line);
            if (tom.empty()) break;
            best = max(best, LCS(agnes, tom));
        }

        cout << best << "\n";
    }
    return 0;
}