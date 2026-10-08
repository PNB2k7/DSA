#include<iostream>
#include<vector>
using namespace std;

void next(int k, vector<pair<int,bool>> v, vector<int> res = {}, int t = 0){
    if(t >= v.size() || res.size()>k) return;
    for(int i=t; i<v.size(); i++){
        if(v[i].second){
            res.push_back(v[i].first);
            v[i].second = false;
            if(k == res.size()){
                for(auto &x : res) cout<<x<<" ";
                cout<<endl;
            }
            else{
                next(k,v,res,i+1);
            }
            res.pop_back();
            v[i].second = true;
        }
    }
}

int main(){
    int n,k; cin>>n>>k;
    int a[1001] = {0};
    for(int i=0; i<n; i++){
        int tmp; cin>>tmp;
        a[tmp] = tmp;
    }
    vector<pair<int,bool>> v;
    for(auto &x: a) if(x) v.push_back(pair(x,true));
    next(k,v);
}