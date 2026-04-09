#include<bits/stdc++.h>
using namespace std;

bool cycle( vector<vector<int>>& adj,
           vector<int>& visited,int src,int p){
            visited[src]=1;
            bool ans=false;
            for(int i=0;i<adj[src].size();i++){
                int node=adj[src][i];
                // if it is not parent than cycle present
                if(visited[node] != -1 && node != p){
                  ans=true;
                }else if(visited[node] == -1){
                    // if not visited 
                    ans=ans || cycle(adj,visited,node,src);
                }
            }
            return ans;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    vector<int> visited(n+1,-1);

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //checking for cycle;
    if(cycle(adj,visited,1,0)){
        cout<<"NO"<<endl;
    }else{
        //check for any disconnected component
        bool istree=true;
        for(int i=1;i<=n;i++){
            if(visited[i] == -1){
                // disconnected componet
               istree=false;
               break;
            }
        }
        if(istree){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}