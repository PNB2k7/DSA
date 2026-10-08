#include<iostream>
#include<map>
using namespace std;
long long mod = 123456789;
long long Try(map<long long, long long> &mp,long long n){
    if(mp[n]) return mp[n];
    else{
        mp[n] = (Try(mp,n-1) + 1)%mod;
        return mp[n];
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        map<long long, long long> mp;
        mp[0] = 1;
        long long n, cnt = 0;
        cin>>n;
        cout<<Try(mp,n)<<endl;
    }
}