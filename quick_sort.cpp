#include<iostream>
using namespace std;

int part(int a[], int left, int right){
    if(left>=right) return -1;
    int i = left+1, j = right;
    while(i<=j){
        while(i<=right && a[i]<a[left]) i++;
        while(j>=left && a[j]>a[left]) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(a[left]>a[j]) swap(a[left],a[j]);
    return j;
}

void quicksort(int a[], int left, int right){
    int pivot = part(a,left,right);
    if(pivot == -1) return;
    quicksort(a,pivot+1,right);
    quicksort(a,left,pivot-1);
}

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    quicksort(a,0,n-1);
    for(auto x: a) cout<<x<<" ";
}
