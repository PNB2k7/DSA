#include<iostream>
#include<vector>
using namespace std;

int check(const vector<int> &v, int k){
    int cnt = 0;
    for(auto &x : v) if(x) cnt++;
    return cnt == k;
}

void next(vector<int> &v, int k){
    if(check(v,k)) {
        for(auto &x : v) cout<<x;
        cout<<endl;
    }
    int i = v.size()-1;
    while(i>=0 && v[i] == 1) v[i--] = 0;
    if(i < 0) return;
    else{
        v[i] = 1;
        next(v,k);
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> v(n,0);
        next(v,k);
    }
}