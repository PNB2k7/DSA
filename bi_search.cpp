#include<iostream>
#include<vector>
using namespace std;

void bi_search(int a[], int k, int left, int right, vector<int> v = {}){
    if(left > right){
        cout<<v.size()<<" ";
        for(auto &x : v) cout<<x<<" ";
        cout<<-1<<endl;
        return;
    }
    int mid = (left + right)/2;
    v.push_back(mid);
    if(a[mid] == k){
        cout<<v.size()<<" ";
        for(auto &x : v) cout<<x<<" ";
        cout<<*v.rbegin()<<endl; 
        return;
    }
    else if(a[mid] > k) bi_search(a,k,left,mid-1,v);
    else bi_search(a,k,mid+1,right,v);
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int a[n];
        for(auto &x: a) cin>>x;
        bi_search(a,k,0,n-1);
    }
}