#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    int n,t; cin>>n>>t;
    set<string> st;
    while(n--){
        string s; cin>>s;
        st.insert(s);
    }
    vector<string> v(st.begin(), st.end());
    vector<int> res(v.size(),0);
    for(int i=0; i<t; i++) res[i] = 1;
    for(int i=0; i<res.size(); i++){
            if(res[i]) cout<<v[i]<<" ";
        }
        cout<<endl; 
    while(prev_permutation(res.begin(),res.end())){
        for(int i=0; i<res.size(); i++){
            if(res[i]) cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}