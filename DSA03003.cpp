#include<iostream>
#include<algorithm>
using namespace std;
long long d = 1000000000 + 7;

int main(){
    long long t; cin>>t;
    while(t--){
        long long n; cin>>n;
        long long a[n], sum=0;
        for(auto &x: a) cin>>x;
        sort(a,a+n);
        for(long long i=0; i<n; i++){
            long long tmp = a[i] * i;
            sum += tmp%d;
        }
        cout<<sum%d<<endl;
    }
}