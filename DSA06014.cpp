#include<iostream>
#include<set>
using namespace std;

set<int> prime;
int a[1000001] ={0};

void sieve(){
    fill(a+2,a+1000001,1);
    for(int i=2; i*i <= 1000000; i++){
        if(a[i]) for(int j = i*i; j <= 1000000; j+=i){
            a[j] = 0;
        }
    }
    for(int i=2; i <= 1000000; i++){
        if(a[i]) prime.insert(i);
    }
}

int main(){
    sieve();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        for(const auto x : prime){
            if(x > n/2){
                cout<<-1<<endl;
                break;
            }
            else{
                if(prime.find(n-x) != prime.end()){
                    cout<<x<<" "<<n-x<<endl;
                    break;
                }
            }
        }
    }
}