#include<iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int a[n];
    for(auto &x:a){
        cin>>x;
    }

    for(int i=0; i<n; i++){
        int c=1;
        for(int j=0; j<n-1-i; j++){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
                c=0;
            }
        }
        if(c) break;
        cout<<"Buoc "<<i+1<<": ";
        for(auto x: a){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
