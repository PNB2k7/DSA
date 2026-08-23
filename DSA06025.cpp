#include<iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        int j = i;
        while(x<a[j-1] && j>0){
            a[j] = a[j-1];
            j--;
        }
        a[j] = x;
        cout<<"Buoc "<<i<<": ";
        for(int t = 0; t<=i; t++){
            cout<<a[t]<<" ";
        }
        cout<<endl;
    }
}
