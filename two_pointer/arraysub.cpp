#include<bits/stdc++.h>
using namespace std;



int main(){
    //                 value,index
    priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto& x : arr)
    cin>>x;
    int k;
    cin>>k;
    int i=0;
    int j=0;
    while(j-i+1 != k){
        pq.push({arr[j],j});
        j++;
    }
    while(j<n){
         pq.push({arr[j],j});
         while(j - pq.top().second >= k ){
            pq.pop();
         }
         j++;
         cout<<pq.top().first<<" ";
    }





return 0;
}