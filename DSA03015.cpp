#include<iostream>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,s,m;
        cin>>n>>s>>m;
        if(n < m) cout<<-1<<endl;
        else{
            int tmp = m * s / n;
            if(tmp * n >= m * s) cout<<tmp<<endl;
            else cout<<tmp + 1<<endl;
        }
    }
}