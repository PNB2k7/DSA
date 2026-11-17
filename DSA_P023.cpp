#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool prime(int n){
    if(n<2) return false;
    for(int i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return true;
}

void next(vector<vector<int>> &ds, vector<int> &v, int n, int k){
    while(true){
        ds.push_back(v);
        int i = v.size()-1;
        while(i>=0 && v[i] == n - (k-i-1)) i--;
        if(i<0) break;
        v[i]++;
        for(int j=i+1; j<k; j++){
            v[j] = v[j-1]+1;
        }
    }
}

int main(){
    int n,k; cin>>n>>k;
    vector<int> v(k);
    for(int i=0; i<k; i++) v[i] = i+1;
    vector<vector<int>> ds;
    next(ds,v,n,k);
    for(int i=1; i<ds.size(); i++){
        if(prime(i+1)){
            cout<<i+1<<": ";
            for(auto &x : ds[i]) cout<<x<<" ";
            cout<<endl;
        }
    }
}