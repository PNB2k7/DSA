#include<iostream>
#include<vector>
using namespace std;

int a[100001] = {0};
const long long LIM = 1000000000000000000LL;
vector<int> prime;
long long f = 1e18;

void sieve(){
    a[0] = a[1] = 1;
    for(int i=2; i*i<=1e5; i++){
        if(!a[i]) for(int j=i*i; j<=1e5; j+=i) a[j] = 1;
    }
    for(int i=2; i<=1e5; i++) if(!a[i]) prime.push_back(i);
}

long long check(vector<int> v){
    long long num = 1, n = v.size();
    for(int j = n-1; j>=0; j--){
        while(v[j]-- > 1){
            if(num > LIM/prime[n-j-1]) return LIM+1;
            num *= prime[n-j-1];
        }
    }
    return num;
}

void Try(int &n, vector<int> &res, int k = 1){ 
    if(check(res) > LIM) return;
    if(k > n) return;
    if(k == n){
        long long c = check(res);
        if(f > c) f = c; 
    }
    int i = 2;
    while(k*i <= n){
        res.push_back(i);
        Try(n,res,k*i);
        res.pop_back();
        i++;
    }
}

int main(){
    sieve();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> res;
        Try(n,res);
        cout<<f<<endl;
        f = 1e18;
    }
}