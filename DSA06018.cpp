#include<iostream>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[100001] = {0}, left = 100002, right = -1;
        for(int i=0; i<n; i++){
            int tmp; cin>>tmp;
            a[tmp] = 1;
            if(left > tmp) left = tmp;
            if (right < tmp) right = tmp;
        }
        int c = 0;
        for(int i = left; i <= right; i++){
            if(a[i] == 0) c++;
        }
        cout<<c<<endl;
    }
}