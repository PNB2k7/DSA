#include<iostream>
#include<vector>
using namespace std;

void Try(const int &n, const int &k, int sum, int &cnt, int m = 1, int index = 0){
    if(index ==k){
        if(sum == 0) cnt++;
        return;
    }
    for(int i = m; i <=n; i++){
        if(sum >= i){
            Try(n,k,sum-i,cnt,i+1,index+1);
        }
        else break;
    }
}

int main(){
    while(true){
        int n,k,s; cin>>n>>k>>s;
        if(n+k+s == 0){
            break;
        }
        vector<int> v(k);
        int cnt = 0;
        Try(n,k,s,cnt);
        cout<<cnt<<endl;
    }
}