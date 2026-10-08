#include<iostream>
#include<vector>
using namespace std;

void next(vector<int> v, int n){
    for(auto &x : v) cout<<x;
    cout<<" ";
    int i = v.size()-1;
    while(v[i] == n - (v.size() - i - 1) && i >= 0) i--;
    if(i < 0) return;
    else{
        v[i++]++;
        for(i; i<v.size(); i++) v[i] = v[i-1] + 1;
    }
    next(v,n);
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> v(k);
        for(int i=0; i<k; i++){
            v[i] = i+1;
        }
        next(v,n);
        cout<<endl;
    }
}