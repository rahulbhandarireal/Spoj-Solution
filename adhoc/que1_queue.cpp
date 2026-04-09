#include<bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> h(n);
        vector<int> ta(n);
        for(auto& x: h)
        cin>>x;
        for(auto&y : ta)
        cin>>y;
        vector<pair<int,int>> ha;
        for(int i=0;i<n;i++){
            ha.push_back({h[i],ta[i]});
        }
        sort(ha.begin(),ha.end(),[](const auto& a,const auto& b){
              if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
       
        int i=n-1;
        while(i>=0){
            int pos=ha[i].second;
            if(pos != 0){
                int from=i;
                int to=i+pos;
                auto val=ha[from];
                ha.erase(ha.begin()+from);
                ha.insert(ha.begin()+to,val);
                ha[to].second=0;
            }
            i--;
        }
        for(auto x : ha)
        cout<<x.first<<" ";
        cout<<endl;
        
    }
return 0;
}