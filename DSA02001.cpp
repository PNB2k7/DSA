#include<iostream>
#include<vector>
using namespace std;

void Try(vector<int> &v){
    if(v.size() == 1) cout<<"["<<v[0]<<"]\n";
    else{
        for(int i=0; i<v.size(); i++){
            if(i == 0) cout<<"["<<v[i];
            else cout<<" "<<v[i];
            if(i == v.size()-1) cout<<"]\n";
        }
        for(int i=0; i<v.size()-1; i++) v[i] = v[i] + v[i+1];
        v.resize(v.size()-1);
        Try(v);
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        for(auto &x : v) cin>>x;
        Try(v);
    }
}