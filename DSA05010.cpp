#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> v(n);
        for(auto &x : v){
            cin>>x;
            x%=k;
        }
        vector<vector<int>> mod(n,vector<int>(k,0));
        mod[0][v[0]] = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<k; j++){
                int t = (v[i] + j) % k;
                if(mod[i-1][j]) mod[i][t] = max(mod[i][t],max(mod[i-1][t], mod[i-1][j] + 1));
                else mod[i][t] = mod[i-1][t];
            }
        }
        cout<<mod[n-1][0]<<endl;
    }
}