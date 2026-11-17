#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int> &v, int k){
    int cnt = 0, c=0;
    for(int i=0; i<v.size(); i++){
        if(v[i] == 1) cnt = 0;
        else{
            cnt++;
            if(cnt > k) return false;
            if(cnt == k){
                if(c) return false;
                else c=1;
            }
        }
    }
    if(c) return true;
    return false;
}

void next(vector<vector<int>> &ds, vector<int> &v, int &k){
    while(true){
        if(check(v,k)) ds.push_back(v);
        int i = v.size()-1;
        while(i>=0 && v[i] != 0) v[i--] = 0;
        if(i < 0) break;
        v[i] = 1;
    }
    cout<<endl;
}

int main(){
    int t; t=1;
    while(t--){
        int n,k; cin>>n>>k;
        vector<vector<int>> ds;
        vector<int> v(n);
        for(auto &x : v) x = 0;
        next(ds,v,k);
        cout<<ds.size()<<endl;
        if(ds.size()) for(auto &x : ds){
            for(auto &y : x) cout<<(y?'B':'A');
            cout<<endl;
        }
    }
}