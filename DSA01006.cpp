#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void next(vector<int> &v){
    while(true){
        for(auto &x : v) cout<<x;
        cout<<" ";
        int i = v.size()-1;
        while(i>0 && v[i]>v[i-1]) i--;
        if(i<=0) return;
        int min = i;
        for(int j=i; j<v.size(); j++) if(v[min] < v[j] && v[j] < v[i-1]) min = j;
        swap(v[min],v[i-1]);
        sort(v.begin()+i, v.end(),greater<int>());
    }
    

}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        for(int i=n; i>0; i--){
            v[n-i] = n - (n-i);
        }
        next(v);
        cout<<endl;
    }
}