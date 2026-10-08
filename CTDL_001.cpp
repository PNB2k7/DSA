#include<iostream>
#include<set>
#include<vector>
using namespace std;

void next_bi(vector<int> &v){
    int i = v.size() - 1;
    while(v[i] != 0 && i > 0){
        v[i--] = 0;
    }
    v[i] = 1;
}

void in(set<vector<int>> &st, vector<int> v, int k = -1){
    vector<int> tmp;
    for(vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++){
        tmp.push_back(*it);
    }
    if(k != -1) tmp.push_back(k);
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        tmp.push_back(*it);
    }
    st.insert(tmp);
}

int main(){
    int n; cin>>n;
    vector<int> start(n/2), end(n/2);
    fill(start.begin(), start.end(), 0);
    fill(end.begin(), end.end(), 1);
    set<vector<int>> st;
    if(n%2){
        for(int i=0; i<=1; i++){
            while(start != end){
                in(st,start,i);
                next_bi(start);
            }
            in(st,end,i);
            fill(start.begin(),start.end(),0);
        }
    }
    else{
        while(start != end){
                in(st,start);
                next_bi(start);
            }
        in(st,end);
    }
    for(auto x:st){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}