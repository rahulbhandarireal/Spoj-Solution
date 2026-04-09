#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin>>n;
    int w,c;
    cin>>w>>c;
    vector<int> arr(n);
    for(auto & x : arr){
        cin>>x;
    }

    deque<int> mini;
    deque<int> maxi;
    int i;
    //making first window using deque
    for(i=0;i<w-1;i++){
        int no=arr[i];
        while(!mini.empty() && arr[mini.back()] > no){
            mini.pop_back();
        }
        mini.push_back(i);
          while(!maxi.empty() && arr[maxi.back()] < no){
            maxi.pop_back();
        }
        maxi.push_back(i);
    }
    vector<int> ans;
    //fidning answer while maintaining queue
    for(;i<n;i++){
        int no=arr[i];
        while(!mini.empty() && arr[mini.back()] > no ){
            mini.pop_back();
        }
        mini.push_back(i);
          while(!maxi.empty() && arr[maxi.back()] < no){
            maxi.pop_back();
        }
        maxi.push_back(i);
        while(i-maxi.front() >= w){
            maxi.pop_front();
        }
         while(i-mini.front() >= w){
            mini.pop_front();
        }
        int s=arr[maxi.front()] - arr[mini.front()];
        if(s<=c){
            //storing 1-based index and always storing first index of window
             
            ans.push_back(i-w+2);
        }
    }

     if(ans.size() >0){
        for(auto x : ans)cout<<x<<endl;
     }else{
        cout<<"NONE"<<endl;
     }



    return 0;
}