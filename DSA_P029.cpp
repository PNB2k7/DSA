#include<iostream>
#include<vector>
using namespace std;

void find(vector<vector<int>> &v, vector<bool> &mark, vector<int> &mvalue, int &f,  vector<int> res = {}, int sum = 0){
    if(res.size() == mark.size()){
        if(f > sum) f = sum;
    }
    for(int i=0; i<v.size(); i++){
        if(!mark[i] && sum + (mark.size() - res.size())*mvalue[*res.rbegin()] < f){
            res.push_back(i);
            mark[i] = true;
            find(v,mark,mvalue,f,res,sum);
            mark[i] = false;
            res.pop_back();
            
        }
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>> v(n,vector<int>(n));
        for(auto &x : v) for(auto &y : x) cin>>y;
        vector<bool> mark(n,false);
        vector<int> res, mvalue(n);
        for(int i=0; i<n; i++){
            int m = 1e7;
            for(auto &x : v[i]) if(x<m) m = x;
            mvalue[i] = m;
        }
        int f=1e7;
        for(int i=0; i<n; i++){
            mark[i] = true;
            res.push_back(i);
            find(v,mark,mvalue,f,res);
            res.pop_back();
            mark[i] = false;
        }
        cout<<f<<endl;
    }
}