#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin>>n;
    while(n !=0){
        vector<int> arr(n);
        for(auto& x : arr){
            cin>>x;
        }
        sort(arr.begin(),arr.end());
        int ans=0;
        int i,j;
        i=0;
        while(i<n){
             j=i+1;
            while(j<n){
                int sum = arr[i] + arr[j];
                // find the first k such that arr[k] >= sum
                auto it = upper_bound(arr.begin() + j + 1, arr.end(), sum);
                int k = it - arr.begin();
                ans += (n - k); // all indices >= k are invalid
                j++;
            }
            i++;
        }
        cout<<ans<<endl;
        cin>>n;

    }



return 0;
}