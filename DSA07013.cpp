#include<iostream>
#include<stack>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        stack<int> st;
        for(auto &x : s){ 
            if(x <= '9' && x >= '0') st.push(x-'0');
            else{
                int a,b;
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                if(x == '*') st.push(a*b);
                else if(x == '+') st.push(a+b);
                else if(x == '-') st.push(b-a);
                else st.push(b/a);
            }
        }
        cout<<st.top()<<endl;
    }
}