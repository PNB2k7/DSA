#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,q; cin>>n>>q;
    vector<int> v(n); 
    for(auto &x : v) cin>>x;
    vector<int> s(v.size());
    s[0] = max(0,v[0]);
    for(int i=1; i<s.size(); i++) s[i] = max(s[i-1],s[i-1]+v[i]);
    while(q--){
        int l,r; cin>>l>>r;
        cout<<s[r-1] - s[l-2]<<endl; 
    }
}