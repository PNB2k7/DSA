#include<iostream>
#include<vector>
using namespace std;

int find(vector<int> &v, int left, int right){
    int i=left+1, j=right;
    while(i<=j){
        while(i<=right && v[left]>=v[i]) i++;
        while(j>left && v[left]<=v[j]) j--;
        if(i<j){
            swap(v[i],v[j]);
        }
    }
    swap(v[left],v[j]);
    return j;
}

void quicksort(vector<int> &v, int left, int right){
    if(left>=right) return;
    int pivot = find(v,left,right);
    quicksort(v,left,pivot-1);
    quicksort(v,pivot+1,right);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        for(auto &x : v) cin>>x;
        quicksort(v,0,n-1);
        for(auto &x : v) cout<<x<<" ";
        cout<<endl;
    }
}