#include<iostream>
#include<vector>
using namespace std;

void insertion(vector<int> v, int n, int i){
    if(i == n) return;
    int x, j=i; cin>>x;
    while(v[j-1] > x && j>0){
        v[j] = v[j-1];
        j--;
    }
    v[j] = x;
    insertion(v,n,i+1);
    cout<<"Buoc "<<i<<": ";
    for(j=0; j<=i; j++){
        cout<<v[j]<<" ";
    }
    cout<<endl;
}

int main(){
    int n; cin>>n;
    vector<int> a(n);
    insertion(a,n,0);
}
