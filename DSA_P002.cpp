#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Next(vector<int> &v, int i = 1){
    cout<<i<<": ";
    for(auto &x : v) cout<<x<<" ";
    cout<<endl;

    int j = v.size()-1;
    while(j >= 0 && v[j] < v[j-1]) j--;
    if(j <= 0) return;
    else{
        int min = j;
        for(int k = j; k < v.size(); k++) if(v[j-1] < v[k] && v[min] > v[k]) min = k;
        swap(v[min], v[j-1]);
        sort(v.begin() + j, v.end());
        Next(v,i+1);
    }
}

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) v[i] = i+1;
    Next(v);
}