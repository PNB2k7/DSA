#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> v(n);
        for(auto &x : v) cin>>x;
        sort(v.begin(), v.end());
        int sum = 0;
        if(k > n-k){
            for(int i=0; i<n-k; i++) sum -= v[i];
            for(int i=n-k; i<n; i++) sum += v[i];
        }
        else{
            for(int i=0; i<k; i++) sum -= v[i];
            for(int i=k; i<n; i++) sum += v[i];
        }
        cout<<sum<<endl;
    }
}