#include<iostream>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,x,k; cin>>n>>x;
        int a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(a[i] == x) k = i;
        }
        cout<<k+1<<endl;
    }
}