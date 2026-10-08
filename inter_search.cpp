#include<iostream>
#include<vector>
using namespace std;

void inter_search(int a[], int k, int left, int right, vector<int> v = {}){
    if(left > right || k < a[left] || k > a[right]){
        cout<<v.size()<<" -1\n";
        return;
    }
    int index = left + (k - a[left])  * (right - left) /(a[right] - a[left]);
    v.push_back(index);
    if(a[index] == k){
        cout<<v.size()<<"size ";
        for(auto &x : v) cout<<x<<" ";
        cout<<*v.rbegin()<<endl;
    }
    else if(a[index] > k) inter_search(a,k,left,index-1,v);
    else inter_search(a,k,index+1,right,v);
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int a[n];
        for(auto &x : a) cin>>x;
        inter_search(a,k,0,n-1);
    }
}