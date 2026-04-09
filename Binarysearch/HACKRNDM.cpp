#include<bits/stdc++.h>
using namespace std;



int main(){

    int n,k;
    cin>>n>>k;

    vector<int> arr(n);
    for(auto& x : arr)
    cin>>x;

    sort(arr.begin(),arr.end());

    int pairs=0;
    for(int i=0;i<n;i++){
        int found=arr[i]+k;
        bool it=binary_search(arr.begin(),arr.end(),found);
        if(it){
            pairs++;
        }
    }
    cout<<pairs<<endl;

return 0;
}