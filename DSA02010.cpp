#include<iostream>
#include<vector>
using namespace std;

void Try(vector<int> &v, int k, vector<vector<int>> &res, int i = 0, vector<int> tmp = {}){
    if(k == 0){
        res.push_back(tmp);
        return;
    }
    for(int j = i; j < v.size(); j++){
        if(v[j] > k) return;
        tmp.push_back(v[j]);
        Try(v,k-v[j],res,j,tmp);
        tmp.pop_back();
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> v(n);
        for(auto &x : v) cin>>x;
        vector<vector<int>> res;
        Try(v,k,res);
        if(res.size()){
            for(auto &x : res){
                cout<<"[";
                for(int i = 0; i < x.size(); i++){
                    cout << x[i] << (i == x.size() - 1 ? "]" : " " );
                }
            }
        }
        else cout<<-1;
        cout<<endl;
    }
}