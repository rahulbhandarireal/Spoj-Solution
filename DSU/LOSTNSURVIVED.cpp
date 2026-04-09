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

class DSU
{

public:
    vector<int> p;
    vector<int> size;
    multiset<int> ms;

    int nodes = 0;

    DSU(int n)
    {
        nodes = n;
        p.resize(n + 1, 0);
        size.resize(n + 1, 1);

        rep(i, 1, n + 1)
        {
            p[i] = i;
            ms.insert(1);
        }
    }

    int find_parent(int v)
    {
        if (p[v] == v)
        {
            return v;
        }
        return p[v] = find_parent(p[v]);
    }

    bool samecom(int a, int b)
    {
        a = find_parent(a);
        b = find_parent(b);
        return a == b;
    }

    void merge_com(int a, int b)
    {
        a = find_parent(a);
        b = find_parent(b);

        if (a != b)
        {
            // remove old sizes
            ms.erase(ms.find(size[a]));
            ms.erase(ms.find(size[b]));
            
            if (size[a] < size[b])
                swap(a, b);
            p[b] = a;
            size[a] += size[b];

            // insert new size
            ms.insert(size[a]);

        }
    }
    int dif()
    {
        return *ms.rbegin() - *ms.begin();
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        dsu.merge_com(a, b);
        cout << dsu.dif() << endl;
    }
}

int main()
{
    fastio;
    solve();
    return 0;
}