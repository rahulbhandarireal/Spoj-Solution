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
 

//dp 
pair<ll, ll> recr(vector<vector<int>> time,
                  vector<vector<int>> &risk, vector<vector<pair<ll, ll>>> &dp,
                  int curnode, int targetnode, int ti, int lt)
{
    if (ti > lt)
        return {INT_MAX, INT_MAX};
    if (curnode == targetnode - 1)
        return {0, ti};
 
    if (dp[curnode][ti].ff != -1)
        return dp[curnode][ti];
 
    pair<ll, ll> op = {INT_MAX, INT_MAX};
    for (int i = 0; i < targetnode; i++)
    {
        if (i == curnode)
            continue;
        pair<ll, ll> temp = recr(time, risk, dp, i, targetnode, ti + time[curnode][i], lt);
        if (temp.ff == INT_MAX)
            continue;
        temp.ff = risk[curnode][i] + temp.ff;
        if (op.ff > temp.ff)
            op = temp;
        else if (op.ff == temp.ff)
        {
            if (op.ss >= temp.ss)
            {
                op = temp;
            }
        }
    }
 
    return dp[curnode][ti] = op;
}
 
void solve()
{
    int n, t;
    cin >> n >> t;
    vector<vector<int>> time, risk;
    rep(i, 0, n)
    {
        vector<int> temp;
        rep(j, 0, n)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        time.push_back(temp);
    }
    rep(i, 0, n)
    {
        vector<int> temp;
        rep(j, 0, n)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        risk.push_back(temp);
    }
    vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(t + 1, {-1, -1}));
    auto ans = recr(time, risk, dp, 0, n, 0, t);
    if (ans.ff == INT_MAX)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << ans.ff << " " << ans.ss << "\n";
    }
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

int INF=INT_MAX;
// djkastra
void solve_dijkstra() {
    int n, T;
    cin >> n >> T;

    vector<vector<int>> time(n, vector<int>(n));
    vector<vector<int>> risk(n, vector<int>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> time[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> risk[i][j];

    // dist[node][time] = min risk
    vector<vector<ll>> dist(n, vector<ll>(T + 1, INF));

    // {risk, node, time}
    priority_queue<
        tuple<ll,int,int>,
        vector<tuple<ll,int,int>>,
        greater<>
    > pq;

    dist[0][0] = 0;
    pq.push({0, 0, 0});

    while(!pq.empty()) {
        auto [currRisk, node, currTime] = pq.top();
        pq.pop();

        if(currRisk > dist[node][currTime]) continue;

        for(int next = 0; next < n; next++) {
            if(next == node) continue;

            int newTime = currTime + time[node][next];
            if(newTime > T) continue;

            ll newRisk = currRisk + risk[node][next];

            if(newRisk < dist[next][newTime]) {
                dist[next][newTime] = newRisk;
                pq.push({newRisk, next, newTime});
            }
        }
    }

    // Find answer at destination
    ll ansRisk = INF;
    int ansTime = -1;

    for(int t = 0; t <= T; t++) {
        if(dist[n-1][t] < ansRisk) {
            ansRisk = dist[n-1][t];
            ansTime = t;
        }
    }

    if(ansRisk == INF) {
        cout << -1 << "\n";
    } else {
        cout << ansRisk << " " << ansTime << "\n";
    }
}

