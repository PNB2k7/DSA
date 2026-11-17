#include<bits/stdc++.h>
using namespace std;

int check(vector<int> &parent, int v){
    if(parent[v] == -1) return v;
    return check(parent,parent[v]);
}

void Kruskal(vector<vector<int>> &p, int V, int E){
    vector<int> parent(V,-1);
    int w = 0;
    for(int i=0; i<E; i++){
        int a = p[i][0]-1, b = p[i][1]-1;
        int pa = check(parent,a), pb = check(parent,b);
        if(pa != pb){
            w += p[i][2]; 
            while(b > -1){
                int tmp = parent[b];
                parent[b] = a;
                b = tmp;
            }
        }
    }
    cout<<w<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        int V,E; cin>>V>>E;
        vector<vector<int>> p(E, vector<int>(3,0));
        for(int i=0; i<E; i++){
            int a,b,c; cin>>a>>b>>c;
            p[i] = {a,b,c};
        }
        sort(p.begin(), p.end(), [](vector<int> &a, vector<int> &b){
            if(a[2] != b[2]) return a[2] < b[2];
            else if(a[0] != b[0]) return a[0] < b[0];
            else return a[1] < b[1];
        });
        Kruskal(p,V,E);
    }
}