#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> v(n,0);
        for(int i=0; i<k; i++) v[i] = 1;
        for(int i=0; i<n; i++){
            if(v[i]) cout<<char(i+65);
        }
        cout<<endl;
        while(prev_permutation(v.begin(),v.end())){
            for(int i=0; i<n; i++){
                if(v[i]) cout<<char(i+65);
            }
            cout<<endl;
        }
    }
}