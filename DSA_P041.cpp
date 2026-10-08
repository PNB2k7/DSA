#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> v(n), even, odd;
    for(auto &x:v){
        int tmp; cin>>tmp;
        if(tmp%2){
            x = 1;
            odd.push_back(tmp);
        }
        else{
            x = 0;
            even.push_back(tmp);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.rbegin(), odd.rend());
    int i,j;
    i=j=0;
    for(auto &x:v){
        if(x) cout<<odd[i++]<<" ";
        else cout<<even[j++]<<" ";
    }
}