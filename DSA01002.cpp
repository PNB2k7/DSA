#include<iostream>
#include<vector>
using namespace std;

void next(vector<int> &v, int n, int k){
    int i = k-1;
    while(i>=0 && v[i] == n - k + i + 1) i--;
    if(i<0){
        for(int j=0; j<k ; j++) cout<<j+1<<" ";
    }
    else{
        v[i]++;
        i++;
        while(i<k){
            v[i] = v[i-1] + 1;
            i++;
        }
        for(auto &x : v) cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> v(k);
        for(auto &x : v) cin>>x;
        next(v,n,k);
    }
}