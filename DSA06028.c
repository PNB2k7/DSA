#include<iostream>
#include<vector>
using namespace std;

void selection(vector<int> v, int n, int t){
    if(t == 0) return;
    int m = n-t;
    for(int i=n-t+1; i<n; i++){
        if(v[m]>v[i]) m=i;
    }
    if(m!=i) swap(v[m],v[i]);
    selection(v,n,t-1);
    cout<<"Buoc "<<n-t+1<<": ";
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x:v) cin>>v;
}
