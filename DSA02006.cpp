#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool check;

void show(vector<int> v){
    for(int i=0; i<v.size(); i++){
        if(i==0) cout<<'[';
        cout<<v[i];
        if(i!=v.size()-1) cout<<" ";
        else cout<<"] ";
    }
}

void subarray(vector<int> v, int n, int max, vector<int> tmp = {}, int index = 0){
    if(max == 0) {
        show(tmp);
        check = true;
        return;
    }
    if(v[index] > max || index ==n) return;
    tmp.push_back(v[index]);
    subarray(v,n,max-v[index],tmp,index+1);
    tmp.pop_back();
    subarray(v,n,max,tmp,index+1);

}

int main(){
    int t; cin>>t;
    while(t--){
        check = false;
        int n,k; cin>>n>>k;
        vector<int> v(n);
        for(auto &x :v) cin>>x;
        sort(v.begin(), v.end());
        subarray(v,n,k);
        if(check == false) cout<<-1;
        cout<<endl;
    }
}
