#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



int main(){
    int t;
    cin>>t;

    while(t--){

        ll n,r,m;
        cin>>n>>r>>m;

        vector<vector<int>> adj(n+1);
        vector<int> visited(n+1,-1);
        visited[0]=1;

        for(int i=0;i<r;i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
         bool ans=true;

        //        real city,cur city,dis left
        queue<pair<int,pair<int,int>>> sp;
        int count=0;
        for(int i=0;i<m;i++){
            int c,s;
            cin>>c>>s;
            if(visited[c] != -1) {
                ans=false;
            }
            visited[c]=c;
            sp.push({c,{c,s}});
            count++;
        }

        if(!ans){ cout<<"No"<<endl;
            continue;
        }
       
        //using multi-source bfs to check all the cities are covered and visited only once
        //making sure that the city of soldier is stored in the queue
        // such that same soldier do not visit twice the same city
        while ((!sp.empty()))
        {
           int rnode=sp.front().first;
           int str=sp.front().second.second;
           int node=sp.front().second.first;
           sp.pop();
        
           if(str > 0){
            for(auto nnode : adj[node]){
                if(visited[nnode] == -1){
                    visited[nnode]=rnode;
                    count++;
                    sp.push({rnode,{nnode,str-1}});
                }else if(visited[nnode] != rnode){
                    // if visited and soilder is different 
                    // than not optimal position
                    ans=false;
                    break;
                }
            }

           }
        }

        if(ans){
            //check all visited or not using count as it reduce time
            if(count == n) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}