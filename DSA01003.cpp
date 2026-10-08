#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void next(vector<int> v){
    int i=v.size()-1;
    while(v[i]<v[i-1] && i>0) i--;
    if(i == 0){
        for(int i=1; i<= v.size(); i++) cout<<i<<" ";
    }
    else{
        int index = i-1, replace = i;
        for(i; i<v.size(); i++){
            if(v[i] > v[index] && v[i] < v[replace]) replace = i;
        }
        swap(v[index], v[replace]);
        sort(v.begin()+index+1,v.end());
        for(auto &x : v) cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        for(auto &x : v) cin>>x;
        next(v);
    }
}  