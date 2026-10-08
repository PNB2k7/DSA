#include<iostream>
#include<vector>
using namespace std;

int f = 10000000;

void cal(int a[100][100], vector<int> &pos, int g=0, vector<int> res = {0}){
    if(res.size() == pos.size()){
        g += a[*res.rbegin()][0];
        f = min(g,f);
        return;
    }
    for(int i=1; i<pos.size(); i++){
        if(pos[i] == 0){
            g += a[*res.rbegin()][i];
            res.push_back(i);
            pos[i] = 1;
            if(g<f) cal(a,pos,g,res);
            pos[i] = 0;
            res.pop_back();
            g -= a[*res.rbegin()][i];
            
        }
    }
}

int main(){
    int n; cin>>n;
    int a[100][100];
    vector<int> pos(n,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    cal(a,pos);
    cout<<f;
}