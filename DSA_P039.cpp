#include<iostream>
#include<vector>
using namespace std;

void Try(vector<vector<int>> &v, vector<int> & mvalue, vector<bool> &mark, int &f, int sum=0, int index=0){
    if(index == v.size()){
        if(f<sum) f = sum;
        return;
    }
    int p = mvalue[index] * (mark.size() - index -1) + sum;
    if(sum + p < f) return;
    for(int i=0; i<v.size(); i++){
        if(!mark[i]){
            mark[i] = true;
            Try(v,mvalue,mark,f,sum + v[index][i], index+1);
            mark[i] = false;
        }
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>> v(n,vector<int>(n));
        vector<bool> mark(n,false);
        vector<int> mvalue(n);
        for(auto &x : v) for(auto &y: x) cin>>y;
        for(int i=0; i<n; i++){
            int m = 0;
            for(auto &x : v[i]) if(m < x) m = x;
            mvalue[i] = m;
        }
        int f = -1;
        Try(v,mvalue,mark,f);
        cout<<f<<endl;
    }
}