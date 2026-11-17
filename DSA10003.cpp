#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &parent, int v){
    if(parent[v] <= 0) return v;
    return find(parent, parent[v]);
}

bool check(vector<pair<int,int>> &p, int V, int E){
    vector<int> parent(V,-1);
    for(auto &x : p){
        int a = x.first-1, b = x.second-1, 
        pa = find(parent,a), pb = find(parent,b);
        if(pa == pb) return true;
        if(parent[pa] < parent[pb]) {
            swap(a,b);
            swap(pa,pb);
        }
        parent[pa] += parent[pb];
        parent[pb] = pa;
    }
    return false;
}

int main(){
    int t; cin>>t;
    while(t--){
        int V,E; cin>>V>>E;
        vector<pair<int,int>> p(E);
        for(auto &x : p) cin>>x.first>>x.second;
        cout<<(check(p,V,E)?"YES\n":"NO\n");
    }
}