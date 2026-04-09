#include<bits/stdc++.h>
using namespace std;

//global parameters for ease of implementation
int glen=INT_MIN;
int gnode;

void farthestnode(vector<vector<int>>& adj,
    int len,
    int node,int p){
        //bc 
        if(glen < len ){ //check at every node
            gnode=node;
            glen=len;
        }
        for(int nnode : adj[node]){
            if(nnode != p){
                farthestnode(adj,len+1,nnode,node);
            }
        }
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> adj(n+1);
    vector<int> visited(n+1,-1);

    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //its a tree,no source is given also it is n-array tree
    //use dfs to find the farthest node, obivously that node
    //is the part of the longest diameter
    glen=INT_MIN;
    farthestnode(adj,0,1,-1);
    //now from the farthest node,using as source find the diameter
    glen=INT_MIN;
    farthestnode(adj,0,gnode,-1);
    cout<<glen<<endl;
    return 0;



}