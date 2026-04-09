#include<bits/stdc++.h>
using namespace std;





int main(){
    string s;
while (cin >> s) {
    //check format;
    bool isJava=false;
    bool isCpp=false;
    int i=1;
    if(isupper(s[0]) || s[0] == '_'){
        cout<<"Error!"<<endl;
        continue;
    }
    int size=s.size();

    while( i<s.size() ){

        if( s[i] == '_' ) isCpp=true;

        if(isCpp && isJava) {
        break;
        }

        if(  isupper(s[i]) ) isJava=true;
        
        if(i< size -1 && s[i] == '_' && s[i+1] == '_'){
        isJava=true;
        isCpp=true;
        break;
        }

        
        if(i == size-1 &&  s[i] == '_' ){
        isJava=true;
        isCpp=true;
        break;
        }

        i++;

    }

     if(isCpp && isJava) {
        cout<<"Error!"<<endl;
        continue;
    }

    if(!isCpp && !isJava){
        cout<<s<<endl;
        continue;
    }

    i=size-1;
    if(isCpp){
        while(i>0){
        while(i>0 && s[i] != '_') i--;
        if(i>0){
        s.erase(i,1);
        s[i]=toupper(s[i]);
        }
        
        i--;
    }
    }else{
        i=1;
        while(i<s.size()){

        while(i<s.size() && !isupper(s[i])) i++;
            if(i<s.size()){
                s[i]=tolower(s[i]);
                 s.insert(i, 1, '_');
                 i+=2;
             }
            
        }

    }
    cout<<s<<endl;





    
}




return 0;
}