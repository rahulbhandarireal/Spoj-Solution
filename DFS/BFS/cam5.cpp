#include<bits/stdc++.h>
using namespace std;


void dfs(int src, vector<vector<int>>& adj, 
    vector<int>& visited){
        visited[src]=1;
        for(int i=0;i<adj[src].size();i++){
            int nnode=adj[src][i];
            if(visited[nnode] == -1){
                dfs(nnode,adj,visited);
            }
        }
}


int main(){
    // here we have to find number of connected components
    // simple dfs and incresing the count it a different compoent is found

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int size;
        cin>>size;
        vector<vector<int>> adj(n);
        for(int i=0;i<size;i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> visited(n,-1);
        int count=0;

        for(int i=0;i<n;i++){

            if(visited[i] == -1){
                count++;
                dfs(i,adj,visited);
            }

        }
        cout<<count<<endl;


    }



}