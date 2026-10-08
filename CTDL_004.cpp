#include<iostream>
using namespace std;

int c = 0;

void count_arr(int a[], int n, int k, int previous = -1000, int index = 0){
    if(k == 0) {
        c++;
        return;
    }
    if(index == n) return;
    if(a[index] > previous){
        count_arr(a,n,k-1,a[index],index+1);
        count_arr(a,n,k,previous,index+1);
    }
    else count_arr(a,n,k,previous,index+1); 
}

int main(){
    int n, k; cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    count_arr(a,n,k);
    cout<<c;
}