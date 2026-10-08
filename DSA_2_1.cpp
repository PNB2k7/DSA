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

    
    if(left < j){
        cout<<"(";
        for(int k=left; k<j; k++){
            cout<<a[k];
            if(k!=j-1) cout<<" ";
        }
        cout<<")";
    }
    cout<<"["<<a[j]<<"]";
    if(j<right){
        cout<<"(";
        for(int k=j+1; k<=right; k++){
            cout<<a[k];
            if(k!=right) cout<<" ";
        }
        cout<<")";
    }
    cout<<endl;

    return j;
}

void quicksort(int a[], int left, int right){
    int pivot = part(a,left,right);
    if(pivot == -1) return;
    quicksort(a,left,pivot-1);
    quicksort(a,pivot+1,right);
}

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    quicksort(a,0,n-1);
}
