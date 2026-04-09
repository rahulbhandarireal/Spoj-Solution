#include<bits/stdc++.h>
using namespace std;

void makePalindrome(vector<int>& arr) {
    int i = 0, j = arr.size() - 1;
    while (i < j) {
        arr[j] = arr[i];
        i++; j--;
    }
}

bool isGreater(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return a.size() > b.size();
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return a[i] > b[i];
    }
    return false;
}

vector<int> nextpalin(vector<int>& arr){

    int i=0;
    int n=arr.size();

    // Special case: all 9s
    if (all_of(arr.begin(), arr.end(), [](int d){ return d == 9; }) ) {
        vector<int> res(n+1, 0);
        res[0] = 1;
        res[n] = 1;
        return res;
    }

    vector<int> pal = arr;
    makePalindrome(pal);

    // If pal > arr, done
    if (isGreater(pal, arr)) return pal;

// Otherwise, increment middle
    int mid = n/2;
    int carry = 1;
    if (n % 2 == 1) {
        arr[mid] += carry;
        carry = arr[mid]/10;
        arr[mid] %= 10;
        mid--;
    } else {
        mid = mid-1;
    }

    while (mid >= 0 && carry) {
        arr[mid] += carry;
        carry = arr[mid]/10;
        arr[mid] %= 10;
        mid--;
    }
    if (carry) arr.insert(arr.begin(), 1);

    pal = arr;
    makePalindrome(pal);
    return pal;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        string n;
        cin>>n;
        vector<int> arr;
        for (char c : n) arr.push_back(c - '0');
        

      arr=nextpalin(arr);

        for (auto& x : arr) cout<<x;
        cout << "\n";
    
    }



return 0;
}