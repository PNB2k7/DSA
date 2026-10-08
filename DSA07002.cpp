#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

void solve(vector<int> &v){
    string tmp;
    getline(cin>>ws,tmp);
    stringstream ss(tmp);
    string word = "";
    ss >> word;
    if(word == "PUSH"){
        ss>>word;
        v.push_back(stoi(word));
    }
    else if(word == "PRINT"){
        if(v.size() == 0) cout<<"NONE\n";
        else cout<<v[v.size()-1]<<endl;
    }
    else{
        if(v.size() != 0) v.pop_back();
    }
}

int main(){
    int n; cin>>n;
    vector<int> v;
    while(n--) solve(v);
}