#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int greed(vector<pair<char,int>> &v, int k, int e, vector<bool> &ept, int i=0){
    if(!v.size()) return 1;
    while(!ept[i]) i++;
    int j=i;
    while(v.begin()->second != 0){
        if(j>=e) return -1;
        ept[j] = false;
        v.begin()->second--;
        j+=k;
    }
    v.erase(v.begin());
    return greed(v,k,e,ept,i+1);
}

int main(){
    int t; cin>>t;
    while(t--){
        int k; cin>>k;
        string s; cin>>s;
        map<char,int> mp;
        for(auto &x : s) mp[x]++;
        vector<pair<char,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](auto &a, auto &b){
            return a.second > b.second;
        });
        vector<bool> ept(s.length(),true);
        cout<<greed(v,k,s.length(),ept)<<endl;
    }
}
