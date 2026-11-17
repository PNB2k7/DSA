#include<iostream>
#include<stack>
using namespace std;

bool check(string &s, stack<char> &st){
    if(!s.size()) return true;
    for(auto &x : s){
        if(x == '(' || x == '{' || x == '[') st.push(x);
        else{
            if(st.empty()) return false;
            if(x == ')' && st.top() != '(') return false;
            if(x == ']' && st.top() != '[') return false;
            if(x == '}' && st.top() != '{') return false;
            st.pop();
        } 
    }
    return st.empty();
}

int main(){
    int t; cin>>t;
    while(t--){
        stack<char> st;
        string s; getline(cin>>ws,s);
        cout<<(check(s,st)?"YES":"NO")<<endl;
    }
}