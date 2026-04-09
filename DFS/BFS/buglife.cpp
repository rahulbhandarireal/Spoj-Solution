#include<bits/stdc++.h>
using namespace std;


bool isSuspecious( vector<vector<int>>& adj,
vector<int>& visited,int src){


    queue<int> qu;
    qu.push(src);
    while(!qu.empty()){
        src=qu.front();
        qu.pop();
    int color;
    if(visited[src] == -1){
        visited[src]=1;
    }
    color=3-visited[src];
    for(int i=0; i<adj[src].size(); i++){
        int nnode=adj[src][i];
        if( visited[nnode] == -1 ){
            visited[nnode]=color;
            qu.push(nnode);
        }else if(visited[nnode] == visited[src]){
           // if two connected nodes have similar colour
           // then suspicious
            return true;
        }
    }
}
    return false;
}

int main(){
    // this question looks like chromatic graph 
    // can we color the graph with two colours only
    int t;
    cin>>t;
    int j=1;
    while(j<=t){
        int s,q;
        cin>>s>>q;
        bool bugs=false;
        vector<vector<int>> adj(s+1);
        for(int i=0;i<q;i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> visited(s+1,-1);
        for(int i=1;i<adj.size();i++){
// bfs and also making bfs for different component
            if(visited[i]==-1 && isSuspecious(adj,visited,i)){
            bugs=true;
            break;
            }
        }
        cout<<"Scenario #"<<j<<":"<<endl;
        if(!bugs)
        cout<<"No suspicious bugs found!"<<endl;
        else
        cout<<"Suspicious bugs found!"<<endl;
        j++;
    }
    return 0;
}