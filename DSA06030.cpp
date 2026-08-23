#include<iostream>
#include<vector>
using namespace std;

void bubble(vector<int> v, int n, int i){
    if(i == n) return;
    int c=1;
    for(int j=0; j<n-i-1; j++){
        if(v[j]>v[j+1]){
            swap(v[j],v[j+1]);
            c=0;
        }
    }
    if(c) return;
    bubble(v,n,i+1);
    cout<<"Buoc "<<i+1<<": ";
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        for(auto &x: v){
            cin>>x;
        }
        bubble(v,n,0);
    }
}
