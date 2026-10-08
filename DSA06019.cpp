#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        map<int,int> mp;
        for(int i=0; i<n; i++){
            int tmp; cin>>tmp;
            mp[tmp]++;
        }
        vector<pair<int,int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](pair<int,int> &a, pair<int,int> &b){
            if(a.second > b.second) return true;
            else if(a.second == b.second) return a.first<b.first;
            return false;
        });
        for(auto &x:v){
            for(int i=0; i<x.second; i++) cout<<x.first<<" ";
        }
        cout<<endl;
    }
}