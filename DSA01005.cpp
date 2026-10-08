#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void next(vector<int> &v){
    for(auto &x : v) cout<<x;
    cout<<" ";
    int i=v.size()-1;
    while(v[i]<v[i-1] && i>0) i--;
    if(i == 0){
        return;
    }
    else{
        int index = i-1, replace = i;
        for(i; i<v.size(); i++){
            if(v[i] > v[index] && v[i] < v[replace]) replace = i;
        }
        swap(v[index], v[replace]);
        sort(v.begin()+index+1,v.end());
    }
    next(v);
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++) v[i] = i+1;
        next(v);
        cout<<endl;
    }
}   