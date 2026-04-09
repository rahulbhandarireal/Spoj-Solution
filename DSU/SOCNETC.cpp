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

class DSU{
 

    public:
    vector<int> p;
    vector<int> size;
    int limit;
     DSU(int n,int limit){
        this->limit=limit;
        p.resize(n+1,0);
        size.resize(n+1,0);
        rep(i,1,n+1){
            p[i]=i;
            size[i]=1;
        }
    }

   int find_parent(int v){
        if(p[v] == v){
            return v;
        }
        return p[v]=find_parent(p[v]);
    }

    bool samecom(int a,int b){
        a=find_parent(a);
        b=find_parent(b);
        return a==b;
    }

    void merge_com(int a,int b){
        a=find_parent(a);
        b=find_parent(b);
        if( (size[a]+size[b]) > limit ) return;

        if(a!=b){
            if(size[a]<size[b])
            swap(a,b);
            p[b]=a;
            size[a]+=size[b];

        }

    }

};



void solve() {
    int n, m;
    cin >> n >> m;
    int q;
    cin>>q;
    DSU dsu(n,m);
    while(q--){
        char ch;
        cin >> ch;
        int a,b;
        switch (ch)
        {
        case 'A':
            cin >> a >> b;
            dsu.merge_com(a,b);
            break;
        case 'E':
            cin >> a >> b;
            cout<<(dsu.samecom(a,b)?"Yes":"No")<<endl;
            break;
        case 'S':
            cin >> a;
            cout << dsu.size[dsu.find_parent(a)] << endl;
            break;
        default:
            break;
        }
    }



}

int main() {
    fastio;
     solve();
    return 0;
}