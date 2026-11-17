#include<iostream>
using namespace std;

void change(string &s){
    string tmp = s;
    for(int i=1; i<s.length(); i++){
        tmp[i] = ((tmp[i-1] - '0') ^ (s[i] - '0')) + '0';
    }
    cout<<tmp<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        change(s);
    }
}