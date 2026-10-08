#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int c = 0;

void solve(vector<int> v, int k, int index = 0, string s= ""){
    if(k == 0){
        for(int i=0; i<s.length(); i++){
            if(s[i] == '1') cout<<v[i]<<" ";
        }
        cout<<endl;
        c++;
        return;
    }
    if(index == v.size()) return;
    for(int i=0; i<=1; i++){
        if(v[index] <= k){
            s.push_back(i+'0');
            solve(v,k-v[index]*i,index+1,s);
            s.pop_back();
        }
        else{
            return;
        }
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for(auto &x:v) cin>>x;
    sort(v.begin(), v.end());
    solve(v,k);
    cout<<c;
}
