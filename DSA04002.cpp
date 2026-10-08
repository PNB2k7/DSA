#include<iostream>
using namespace std;

const long long d = 1e9 + 7;

long long exponent(long long n, long long k){
    if(k == 0) return 1;
    n %= d;
    if(k == 1) return n;
    if(k%2) return (exponent(n*n ,k/2) * n) % d;
    else return exponent(n*n ,k/2) % d;
}

int main(){
    int t; cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long t = n, k = 0;
        while(t){
            k = k*10 + t%10;
            t/=10;
        }
        cout<<exponent(n,k)<<endl;
    }
}