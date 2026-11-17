#include<bits/stdc++.h>
using namespace std;

int flag = 1;

void inorder(vector<int> &v, int i){
    if(v[i*2+1] != -1) inorder(v,i*2+1);
    cout<<v[i]<<" ";
    if(v[i*2+2] != -1) inorder(v,i*2+2);
}

int main(){
    int t; cin>>t;
    while(t--){
        vector<int> pos(1e4+1,-1), v(1e4+1,-1);
        set<int> st;
        int n; cin>>n;
        for(int i=0; i<n; i++){
            int a,b; cin>>a>>b;
            char x; cin>>x;
            if(pos[a] == -1){
                pos[a] = 0;
                v[pos[a]] = a;
                st.insert(a);
            }
            if(x == 'L') pos[b] = pos[a]*2 + 1;
            else pos[b] = pos[a]*2 + 2;
            v[pos[b]] = b;
            st.insert(b);
        }
        for(auto &x : st) cout<<x<<" ";
        cout<<endl;
    }
}