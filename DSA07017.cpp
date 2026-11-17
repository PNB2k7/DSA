#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n), res(n);
        for(auto &x : v) cin>>x;
        stack<pair<int,int>> st;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && st.top().first <= v[i]) st.pop();
            if(st.empty()) res[i] = -1;
            else res[i] = st.top().second;        
            int flag = 1;
            for(int j = i+1; j < n; j++){
                if(v[j] < v[i]){
                    st.push({v[i],v[j]});
                    flag = 0;
                    break;
                }
            }
            if(flag) st.push({v[i],-1});
        }
        for(auto &x : res) cout<<x<<" ";
        cout<<endl; 
    }
}