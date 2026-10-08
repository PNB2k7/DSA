#include<iostream>
#include<string>
using namespace std;

void next(string s){
    int i = s.length()-1;
    while(i>=0 && s[i] == '1') s[i--] = '0';
    if(i<0){
        for(auto &x : s) cout<<"0";
    }
    else{
        s[i] = '1';
        cout<<s;
    }
    cout<<endl;
}

int main(){
    int n; cin>>n;
    while(n--){
        string s; cin>>s;
        next(s);
    }
}