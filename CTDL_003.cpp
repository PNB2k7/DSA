#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<int> res;
int value = -1;

int cal(const vector<int> &c, vector<int> tmp){
    int sum = 0;
    for(int i=0; i<c.size(); i++) if(tmp[i]) sum += c[i];
    return sum; 
}

int FOPT(const vector<int> &a, const vector<int> &c, const int &w, vector<int> tmp){
    if(w >= cal(a,tmp)){
        int tmp_value = cal(c,tmp);
        if(tmp_value>=value){
            value = tmp_value;
            res = tmp;
        }
    }
    int i = tmp.size() - 1;
    while(i >= 0 && tmp[i] != 0) tmp[i--] = 0;
    if(i < 0) return 0;
    else tmp[i] = 1;
    return FOPT(a,c,w,tmp);
}

int main(){
    int n,w; cin>>n>>w;
    vector<int> a(n), c(n), tmp(n,0);
    for(auto &x : c) cin>>x;
    for(auto &x : a) cin>>x;
    FOPT(a,c,w,tmp);
    cout<<value<<endl;
    for(auto &x : res) cout<<x<<" ";
}