#include<bits/stdc++.h>
using namespace std;



int main(){
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);

    for(auto&x : arr){
        cin>>x;
    }

    int i=0;
    int j=0;
    int cost=0;
    int gcost=INT_MIN;
    while(j<n ){
        while( cost > m && i < j ){
            cost=cost-arr[i];
            i++;
        }
        gcost=max(gcost,cost);
        if(arr[j] > m) {
            j++;
            continue;
        }
        cost=cost+arr[j]; 
        j++;  
    }
       while( cost > m && i < j ){
            cost=cost-arr[i];
            i++;
        }

    gcost=max(gcost,cost);
    cout<<gcost<<endl;

return 0;
}