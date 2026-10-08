#include<iostream>
#include<vector>
using namespace std;

int bi_search(vector<int> v, int k, int left, int right){
    if(left>right) return -1;
    int mid = (left + right)/2;
    if(v[mid] == k) return 1;
    else if(v[mid] > k) return bi_search(v,k,left,mid-1);
    else return bi_search(v,k,mid+1,right);
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> v(n);
        for(auto &x: v) cin>>x;
        cout<<bi_search(v,k,0,n-1)<<endl;
    }
}