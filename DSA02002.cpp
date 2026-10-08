#include<iostream>
#include<vector>
using namespace std;

void show(vector<int> v){
    for(int i=0; i<v.size(); i++){
        if(i==0) cout<<'[';
        cout<<v[i];
        if(i!=v.size()-1) cout<<" ";
        else cout<<"] ";
    }
}

void triangle(vector<int> v){
    if(v.size() == 1){
        show(v);
        return;
    }
    vector<int> n(v.size()-1);
    for(int i=0; i<n.size(); i++){
        n[i] = v[i+1] + v[i];
    }
    triangle(n);
    show(v);
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        for(auto &x:v) cin>>x;
        triangle(v);
        cout<<endl;
    }
}