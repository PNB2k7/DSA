#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        for(auto &x : v) cin>>x;
        sort(v.begin(),v.end());
        if(n%2) cout<<v[n/2]<<endl;
        else cout<<v[n/2-1]<<endl;
    }
}