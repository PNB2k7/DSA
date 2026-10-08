#include<iostream>
#include<map>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        map<long long, int> mp;
        int n, t = 1; cin>>n;
        long long a[n];
        for(auto &x: a){
            cin>>x;
            mp[x]++;
        }
        for(auto &x: a){
            if(mp[x] > 1){
                cout<<x<<endl;
                t = 0;
                break;
            }
        }
        if(t) cout<<"NO\n";
    }
}