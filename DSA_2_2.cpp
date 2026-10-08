#include<iostream>
#include<vector>
using namespace std;

void show(vector<int> v){
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        if(it == v.begin()) cout<<"(";
        cout<<*it;
        if(it == v.end()-1) cout<<")";
        else cout<<" ";
    }
}

void quicksort(vector<int> v){
    if(v.size()<=1) return;
    vector<int> left;
    vector<int> right;
    for(vector<int>::iterator it = v.begin()+1; it != v.end(); it++){
        if(*it>v[0]) left.push_back(*it);
        else right.push_back(*it);
    }
    show(left);
    cout<<"["<<v[0]<<"]";
    show(right);
    cout<<endl;
    quicksort(left);
    quicksort(right);
}

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x:v) cin>>x;
    quicksort(v);
}