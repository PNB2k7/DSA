#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n), fre(n), res(n);
        map<int,int> mp;
        for(auto &x : v){
            cin>>x;
            mp[x]++;
        }
        for(int i=0; i<n; i++) fre[i] = mp[v[i]];
        stack<pair<int,int>> st;
        for(int i=n-1; i>=0; i--){
            while(true){
                if(st.empty()){
                    res[i] = -1;
                    st.push({fre[i],v[i]});
                    break;
                }
                if(st.top().first <= fre[i]) st.pop();
                else{
                    res[i] = st.top().second;
                    st.push({fre[i],v[i]}) ;
                    break;
                }
            }
        }
        for(auto &x : res) cout<<x<<" ";
        cout<<endl;
    }
}