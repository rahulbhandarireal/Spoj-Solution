#include<bits/stdc++.h>
using namespace std;

bool isPrime(string no){
    int n=0;
    if(no[0] == '0') return false;
    for(int i=0;i<4;i++){
        int rem=no[i] - '0';
        n=n*10+rem;
    }
    int limit=sqrt(n);
    for(int i=2;i<=limit;i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        int n1,n2;
        cin>>n1>>n2;
        string a="",b="";
        while(n1>0){
            int rem=n1%10;
            a=char(rem + '0') + a;
            n1/=10;
        }
        while(n2>0){
            int rem=n2%10;
            b=char(rem + '0') + b;
            n2/=10;
        }
        queue<pair<string,int>> qu;
        qu.push({a,0});
        int ans=INT_MAX;
        unordered_set<string> st;
        st.insert(a);
        while (!qu.empty())
        {
            string start=qu.front().first;
            int steps=qu.front().second;
            qu.pop();
            if(start == b){
               ans=min(steps,ans);
            }

            for(int i=0;i<4;i++){
                int cur= start[i]-'0';
                for(int j=0;j<=9;j++){
                    if(cur != j){
                        start[i]=j+'0';
                        if(st.find(start) == st.end() 
                        && isPrime(start)){
                            qu.push({start,steps+1});
                            st.insert(start);
                        }
                    }
                }
                start[i]=cur + '0';
            }
        }
        if(ans == INT_MAX){
            cout<<"Impossible"<<endl;
        }else{
            cout<<ans<<endl;
        }

    
    }

return 0;

}