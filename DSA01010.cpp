#include<iostream>
#include<vector>
using namespace std;

int next(vector<int> &v, int n, int k){
    vector<int> tmp = v;
    int i = k-1;
    while(i>=0 && v[i] == n - k + i + 1) v[i--];
    if(i<0) return k    ;
    v[i++]++;
    while(i<k){
        v[i] = v[i-1] + 1;
        i++;
    }
    int cnt = 0, x = 0, y = 0;
    while(x < k && y < k){
        if(tmp[x] == v[y]){
            cnt++;
            x++;
            y++;
        }
        else if(tmp[x] < v[y]) x++;
        else y++;
    }
    return k-cnt;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> v(k);
        for(auto &x : v) cin>>x;
        cout<<next(v,n,k)<<endl;
    }
}