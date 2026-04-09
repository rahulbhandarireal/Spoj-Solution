#include <bits/stdc++.h>
using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define rep(i, a, b) for (int i = a; i < b; i++)
#define repr(i, a, b) for (int i = a; i >= b; i--)

#define vin(v, n)               \
    for (int i = 0; i < n; i++) \
        cin >> v[i];
#define vout(v)           \
    for (auto &x : v)     \
        cout << x << " "; \
    cout << "\n";

#define YES cout << "YES\n";
#define NO cout << "NO\n";

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << "\n";
#else
#define debug(x)
#endif

// simple greedy problem it was looking like dp, just take the maximum value and use it as early as possible
void solve()
{
    int n, a;
    cin >> n >> a;
    n--;
    a--;
    vector<pair<int, int>> x(n, {0, 0}), y(a, {0, 0});

    rep(i, 0, n)
    {
        int t;
        cin >> t;
        x[i] = {t, 0};
    }
    rep(i, 0, a)
    {
        int t;
        cin >> t;
        y[i] = {t, 0};
    }

    sort(x.begin(), x.end(), [](const auto &a, const auto &b)
         { return a.ff > b.ff; });

    sort(y.begin(), y.end(), [](const auto &a, const auto &b)
         { return a.ff > b.ff; });

    int tomx = 1;
    int tomy = 1;
    int ans = 0;

    while (!x.empty() || !y.empty())
    {
        auto xf = (x.empty()) ? make_pair(INT_MIN, -1) : x.front();
        auto yf = (y.empty()) ? make_pair(INT_MIN, -1) : y.front();

        if (xf.ff > yf.ff)
        {
            ans += xf.ff * tomx;
            x.erase(x.begin());
            tomy++;
        }
        else if (xf.ff < yf.ff)
        {
            ans += yf.ff * tomy;
            y.erase(y.begin());
            tomx++;
        }
        else
        {
            if (tomx >= tomy)
            {
                ans += xf.ff * tomx;
                x.erase(x.begin());
                tomy++;
            }
            else
            {
                ans += yf.ff * tomy;
                y.erase(y.begin());
                tomx++;
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}