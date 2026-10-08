#include<iostream>
using namespace std;

void radix_sort(int a[], int n){
    for(int shift=0; shift<=1; shift++){
        int bin[10] = {0}, tmp[n];
        for(int i=0; i<n; i++){
            tmp[i] = a[i];
            int c = a[i];
            for(int d = 0; d<shift; d++){
                c /= 10;
            }
            bin[c%10]++;
        }
        int index[10] = {0};
        for(int i=1; i<10; i++){
            index[i] = bin[i-1] + index[i-1];
        }

        for(int i=0; i<n; i++){
            int c = tmp[i];
            for(int d = 0; d<shift; d++){
                c /= 10;
            }
            a[index[c%10]] = tmp[i];         
            index[c%10]++; 
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(j<=i) cout<<a[j]<<" ";
                else cout<<"x ";
            }
            cout<<endl;
        }
    }
}

int main(){
    int n; cin>>n;
    int a[n];
    for(auto &x : a) cin>>x;
    radix_sort(a,n);
}