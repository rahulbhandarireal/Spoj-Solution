#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


ll getWood(vector<ll>& arr,ll h){
    ll s=0;

    for(auto x : arr){
   if(x>h) s+=(x-h);
    }
    return s;

}
int main(){

    int n,m;
    cin>>n>>m;

    vector<ll> ar(n);
    for(auto& x: ar)
    cin>>x;
    ll high=*max_element(ar.begin(),ar.end());
    ll low=0;
    ll ans=-1;
    while(low<=high){
        ll mid=low+(high-low)/2;

        ll accumulated_wood=getWood(ar,mid);

        if(accumulated_wood >= m){
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    cout<<ans<<endl;

return 0;
}