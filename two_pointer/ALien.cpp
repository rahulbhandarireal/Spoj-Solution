#include<bits/stdc++.h>
using namespace std;



int main(){

    int t;
    cin>>t;
    while(t--){
        int n,l;
        cin>>n>>l;

        vector<int> arr(n);
        for(auto& x: arr)
        cin>>x;
        int i=0;
        int j=0;
        int sum=0;
        int maxsize=0;
        int w=0;
        while(i<n && j<n){
            if(arr[j] > l){
                i=j+1;
                j++;
                continue;
            }
            if( sum + arr[j] <= l ){
                sum+=arr[j];
                if( maxsize <= j-i+1 ){
                    if( (maxsize == j-i+1 && w>sum )
                || ( maxsize < j-i+1)){
                maxsize=j-i+1;
                w=sum;
                    }
            }
                j++;
            }else if( sum + arr[j] > l ){
                sum-=arr[i];
                i++;
            }
          
        }

        cout<<w<<" "<<maxsize<<endl;
    }
return 0;
}