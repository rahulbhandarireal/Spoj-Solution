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
   
     DSU(int n){
        p.resize(n+1,0);
        size.resize(n+1,1);
        rep(i,1,n+1){
            p[i]=i;
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

        if(a!=b){
            if(size[a]<size[b])
            swap(a,b);
            p[b]=a;
            size[a]+=size[b];
        }

    }

};

void solve() {
    int n,q;
    cin >> n >> q; 
    DSU dsu( 2*q + 5 );
    unordered_map<int,int> mp;
    int idx=1;
   
    while(q--){
        int a,b;
        cin >> a >> b;
        if(mp.find(a) == mp.end())
        mp[a]=idx++;
        if(mp.find(b) == mp.end())
        mp[b]=idx++;

        dsu.merge_com(mp[a],mp[b]);
    }
    
    int mpcount=mp.size();
    int rem=n-mpcount;
    unordered_set<int> np;

    for(auto x : mp){
        np.insert(dsu.find_parent(x.ss));
    }
    cout<< rem+ (int)np.size()<<endl;
}

int main() {
    fastio;
     solve();
    return 0;
}