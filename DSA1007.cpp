#include<iostream>
#include<vector>
using namespace std;

void next(vector<int> &v){
    while(true){
        for(auto &x : v) cout<<(x?'B':'A');
        cout<<" ";
        int i = v.size()-1;
        while(i>=0 && v[i] != 0) v[i--] = 0;
        if(i < 0) break;
        v[i] = 1;
    }
    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        for(auto &x : v) x = 0;
        next(v);
    }
}