#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<long long> v(n),s(m);
        for(auto &x : v) cin>>x;
        for(auto &x : s) cin>>x;
        sort(s.begin(),s.end());
        sort(v.rbegin(), v.rend());
        cout<<v[0]*s[0]<<endl;
    }
}