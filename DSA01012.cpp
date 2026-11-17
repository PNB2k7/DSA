#include<iostream>
#include<vector>
using namespace std;

void next(vector<int> &v){
    while(true){
        vector<int> tmp(v.size());
        tmp[0] = v[0];
        for(int i=1; i<v.size(); i++) tmp[i] = v[i-1] ^ v[i];
        for(auto &x : tmp) cout<<x;
        cout<<" ";
        int k = v.size()-1;
        while(k>=0 && v[k] != 0){
            v[k] = 0;
            k--;
        }
        if(k < 0) break;
        v[k] = 1;
    }
    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n,0);
        next(v);
    }
}