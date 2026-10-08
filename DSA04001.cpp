#include<iostream>
using namespace std;
long long d = 1e9 + 7;

long long exponent(long long n, long long k){
    if(k == 1) return n % d;
    if(k%2) return (exponent(n*n % d ,k/2) * n) % d;
    else return exponent(n*n % d ,k/2) % d;
}

int main(){
    int t; cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        cout<<exponent(n,k)<<endl;
    }
}