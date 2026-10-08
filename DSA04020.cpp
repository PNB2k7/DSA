#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> &v, int k, int left, int right){
    if(left > right) return 0;
    int mid = (right + left)/2;
    if(v[mid] == k) return mid+1;
    else if(v[mid] < k) return search(v,k,mid+1,right);
    else return search(v,k,left,mid-1);
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> v(n);
        for(auto &x : v) cin>>x;
        int t = search(v,k,0,n-1);
        if(t) cout<<t<<endl;
        else cout<<"NO\n";
    }
}