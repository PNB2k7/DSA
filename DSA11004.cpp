#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        vector<int> v(1e5, -1), pos(1e5,-1);
        int flag = 1;
        int n; cin>>n;
        for(int i=0; i<n; i++){
            int a,b; cin>>a>>b;
            char x; cin>>x;
            if(flag){
                flag = 0;
                pos[a] = 0;
                v[pos[a]] = a;
            }
            if(x == 'R') {
                pos[b] = pos[a]*2+2;
                v[pos[b]] = b; 
            }
            else{
                pos[b] = pos[a]*2+1;
                v[pos[b]] = b;
            }
        }
        for(auto &x : v) if(x!=-1) cout<<x<<" ";
        cout<<endl;
    }
}