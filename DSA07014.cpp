#include<iostream>
#include<stack>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        string s,rever; cin>>s;
        for(int i = s.length()-1; i>=0; i--) rever.push_back(s[i]);
        stack<int> st;
        for(auto &x : rever){
            if(x <= '9' && x >= '0') st.push(x-'0');
            else{
                int a,b;
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                if(x == '*') st.push(a*b);
                else if(x == '+') st.push(a+b);
                else if(x == '-') st.push(a-b);
                else st.push(a/b);
            }
        }
        cout<<st.top()<<endl;
    }
}