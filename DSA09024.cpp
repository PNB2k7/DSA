#include<bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> &ls, int u){
    queue<int> st;
    vector<bool> mark(ls.size(), false);
    st.push(u);
    vector<int> res;
    while(!st.empty()){
        u = st.front();
        st.pop();
        if(mark[u]) continue;
        mark[u] = true;
        res.push_back(u);
        for(int i=0; i<ls[u].size(); i++){
            if(!mark[ls[u][i]]) st.push(ls[u][i]);
        }
    }
    for(auto &x : res) cout<<x+1<<" ";
    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        int v, e, u; cin>>v>>e>>u;
        vector<vector<int>> ls(v);
        for(int i=0; i<e; i++){
            int a,b; cin>>a>>b;
            ls[a-1].push_back(b-1);
        }
        BFS(ls,u-1);
    }
}