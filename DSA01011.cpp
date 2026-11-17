#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

void next(string &s){
    int i = s.length()-1;
    while(i>0 && s[i] - '0' <= s[i-1] - '0') i--;
    if(i<=0) {
        s = "BIGGEST";
        return;
    }
    int m = i;
    for(int j = i; j<s.length(); j++) if(s[j] - '0' > s[i-1] - '0' && s[j] - '0' <s[m] - '0') m = j;
    swap(s[i-1],s[m]);
    sort(s.begin()+i, s.end());
}

int main(){
    int t; cin>>t;
    map<int,string> mp;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        mp[n] = s;
    }
    for(auto &x : mp) next(x.second);
    for(auto &x : mp){
        cout<<x.first<<" "<<x.second<<endl;
    }
}