#include<iostream>
#include<vector>
using namespace std;

void mark(vector<vector<int>> &v, int i, int j){
    v[i][j] = 0;
    for(int x = i-1; x <= i+1; x++){
        for(int y = j-1; y <= j+1; y++){
            if(x < 0 || x >= v.size() || y < 0 || y >= v[0].size()) continue;
            if(x != i && y != j) continue;
            if(v[x][y]) mark(v,x,y);
        }
    }
}

void find(vector<vector<int>> &v, int &cnt){
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            if(v[i][j]) {
                mark(v,i,j);
                cnt++;
            }
        }
    }
}

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(auto &x : v) for(auto &y : x){
        char tmp; cin>>tmp;
        if(tmp == '#') y = 1;
    }
    int cnt = 0;
    find(v,cnt);
    cout<<cnt;
}