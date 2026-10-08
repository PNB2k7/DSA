#include<iostream>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(auto &x:a) cin>>x;
        int b[3]={0};
        for(auto &x:a){
            b[x]++;
        }
        for(int i=0; i<=2; i++){
            while(b[i]--){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
}