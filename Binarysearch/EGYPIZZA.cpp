#include<iostream>
using namespace std;


int canGive(int temp,int sum,int h,int q,int tq){
    int s=1;
    //just do some basic maths
    //a portion cannot we prepared by adding left over
    //ex-> 1/2 cannot be made from 3/4 and 3/4
    //but 2 1/2 can be made from 1 pizza
    // 4 1/4 can be made from 1 pizza
    // 1 3/4 and 1 1/4 can be made from 1
    // 2 1/4 and 1 1/2 can be made from 1
    while( temp > 0 && sum !=0 ){
            if(h>=2){
                h-=2;    
            }else if(h>=1 && q>=1){
                h--;
                q=(q-2>=0)?q-2:0;
            }else if(tq>=1 && q>=1){
                tq--;
                q--;
            }else if(h >= 1){
                h--;
            }else if(tq>=1){
                tq--;
            }else if(q>=1){
                q=(q-4>=0)?q-4:0;
            }else if(s>0){
                s--;
            }
            temp--;
            sum=h+tq+q+s;
        }
        

        if( sum <= 0 ){
        return true;
        }else
        return false;


}
int main(){

    int n;
    cin>>n;

    int q=0,h=0,tq=0;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        if(x == "1/2"){
            h++;
        }else if(x == "1/4"){
            q++;
        }else if(x == "3/4"){
            tq++;
        }
    }
    

    int low=1;
    int high=n+1;
    int ans=-1;

    while(low<=high){
        int mid=low+(high - low )/2;
        int temp=mid;
        int sum=h+tq+q+1;
        //this logic was important
        bool isPossible=canGive(temp,sum,h,q,tq);
        if(isPossible){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }  
    }
    cout<<ans<<endl;

return 0;
}