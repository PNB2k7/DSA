#include<bits/stdc++.h>
using namespace std;

void show(vector<int> &pre, int v){
    if(pre[v] == -1){
        cout<<v+1;
        return;
    }
    show(pre, pre[v]);
    cout<<" "<<v+1;
}

void DFS(vector<vector<int>> &ls, int u, int v){
    stack<int> st;
    vector<bool> mark(ls.size(), false);
    st.push(u);
    mark[u] = true;
    vector<int> pre(ls.size(),-1);
    while(!st.empty()){
        u = st.top();
        st.pop();
        if(u == v) break;
        for(int i=ls[u].size()-1; i>=0; i--){
            if(!mark[ls[u][i]]) {
                st.push(ls[u][i]);
                pre[ls[u][i]] = u;
                mark[ls[u][i]] = true;
            }
        }
    }
    if(pre[v] == -1) cout<<-1;
    else show(pre,v);
    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        int v, e, u, k; cin>>v>>e>>u>>k;
        vector<vector<int>> ls(v);
        for(int i=0; i<e; i++){
            int a,b; cin>>a>>b;
            ls[a-1].push_back(b-1);
        }
        DFS(ls,u-1,k-1);
    }
}