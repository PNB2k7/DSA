#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void quicksort(vector<int> v,int k){
    if(v.size() <= 0) return;
    vector<int> left, right;
    for(vector<int>::iterator it = v.begin()+1; it != v.end(); it++){
        if(abs(*it)<abs(v[0])) left.push_back(*it);
        else right.push_back(*it);
    }
    quicksort(left,k);
    cout<<v[0]+k<<" ";
    quicksort(right,k);
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> v(n);
        for(auto &x:v){
            int tmp; cin>>tmp;
            x = tmp - k;
        }
        quicksort(v,k);
        cout<<endl;
    }
}