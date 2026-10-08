#include<iostream>
using namespace std;
long long mod = 1e9 + 7;

long long expo(long long a, long long b){
    if(b==0) return 1;
    if(b == 1) return a;
    long long c = (a * a) % mod;
    if(b%2) return (a * expo(c,b/2))%mod;
    else return expo(c,b/2);
}

int main(){
    while(1){
        long long a,b; cin>>a>>b;
        if(a + b == 0) break;
        cout<<expo(a,b)<<"\n";
    }
}