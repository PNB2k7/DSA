#include<bits/stdc++.h>
using namespace std;

void Dijkstra(vector<vector<pair<int,int>>> &ls, int u){
    vector<int> mark(ls.size(),0), res(ls.size(),1e9), pre = {u};
    mark[u] = 1; res[u] = 0;
    for(auto &x : ls[u]){
        res[x.first] = x.second;
    }
    while(pre.size() < ls.size()){
        int index = 0;
        while(mark[index]) index++;
        for(int i=index; i<ls.size(); i++){
            if(!mark[i] && res[i] < res[index]) index = i;
        }
        pre.push_back(index);
        mark[index] = 1;
        for(auto &x : ls[index]){
            res[x.first] = min(res[x.first], res[index] + x.second);
        }
    }
    for(auto &x : res) cout<<x<<" ";
    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        int v,e,u;  cin>>v>>e>>u;
        vector<vector<pair<int,int>>> ls(v);
        for(int i=0; i<e; i++){
            int a,b,c; cin>>a>>b>>c;
            ls[a-1].push_back({b-1,c});
            ls[b-1].push_back({a-1,c});
        }
        Dijkstra(ls,u-1);
    }
}