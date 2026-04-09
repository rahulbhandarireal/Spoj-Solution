#include<bits/stdc++.h>
using namespace std;

int findVolume(int src,
    vector<vector<int>>& adj,
    vector<int>& volume,
               int p){
                int child=0;
                int curV=0;
                for(int nnode : adj[src]){
                    // counting child node and excluding parent node
                    if(nnode != p){
                        child++;
                        curV+=findVolume(nnode,adj,volume,src);
                    }
                }
                // base case is handled here 
                // leaf node will have 1 volume
                volume[src]=(child+1)+curV;
                return volume[src];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> adj(n);

        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }


        vector<int> volume(n);

        findVolume(0,adj,volume,-1);
        int ans=0;
        // volume is sum of all the node's length 
        for(int v : volume){
            ans+=v;
        }
        cout<<ans<<endl;
    }
    return 0;
}