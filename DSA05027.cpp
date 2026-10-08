#include<iostream>
#include<vector>
#include<map>
using namespace std;

int dynamic(vector<pair<int,int>> &item, int i, int v, vector<vector<int>> &mp){
    if(i<0) return 0;
    if(mp[i][v]) return mp[i][v];
    else{
        if(item[i].first <= v) {
            mp[i][v] = max(dynamic(item,i-1,v-item[i].first,mp) + item[i].second, dynamic(item,i-1,v,mp));
        }
        else {
            mp[i][v] = dynamic(item,i-1,v,mp);
        }
        return mp[i][v];
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,v; cin>>n>>v;
        vector<pair<int,int>> item(n);
        for(auto &x : item) cin>>x.first;
        for(auto &x : item) cin>>x.second;
        vector<vector<int>> mp(1001,vector<int>(1001,0));
        cout<<dynamic(item,n-1,v,mp)<<endl;
    }
}