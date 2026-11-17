#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n),m(n);
        stack<int> st;
        for(auto &x : v) cin>>x;
        for(int i=v.size(); i>=0; i--){
            while(!st.empty() && st.top() <= v[i]) st.pop(); 
            if(st.empty()) {
                m[i] = -1;
                st.push(v[i]);
            }
            else{
                m[i] = st.top();
                st.push(v[i]);
            }   
        }
        for(auto &x : m) cout<<x<<" ";
        cout<<endl;
    }
}