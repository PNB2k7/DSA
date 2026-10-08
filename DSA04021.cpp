#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

ll a[94] = {0};

void cal(){
    a[1] = 1;
    a[2] = 1;
    for(int i=3; i<=93; i++) a[i] = a[i-1] + a[i-2];
}

char find(int n, ll k){
    if(n == 1) return '0';
    else if (n == 2) return '1';
    else{
        if(k <= a[n-2]) return find(n-2,k);
        else return find(n-1,k-a[n-2]);
    }
}


int main(){
    cal();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll k; cin>>k;
        cout<<find(n,k)<<endl;
    }
}