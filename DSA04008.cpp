#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

vector<ll> multi(vector<ll> a, vector<ll> b){
    vector<ll> tmp(4);
    tmp[0] = (a[0]*b[0]%mod + a[1]*b[2]%mod)%mod;
    tmp[1] = (a[0]*b[1]%mod + a[1]*b[3]%mod)%mod;
    tmp[2] = (a[2]*b[0]%mod + a[3]*b[2]%mod)%mod;
    tmp[3] = (a[2]*b[1]%mod + a[3]*b[3]%mod)%mod;
    return tmp;
}

vector<ll> fibo(vector<ll> a, int n){
    if(n == 1) return a;
    vector<ll> tmp = multi(a,a);
    if(n%2) return multi(a,fibo(tmp,n/2));
    else return fibo(tmp,n/2);  
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll> v = {1,1,1,0};
        vector<ll> res = fibo(v,n);
        cout<<res[1]<<endl;
    }
}