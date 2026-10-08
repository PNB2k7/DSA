#include<iostream>
#include<vector>
#include<string>
using namespace std;

int dynamic(vector<vector<int>> &v, string &a, string &b, int la, int lb){
    for(int i=1; i<=la; i++){
        for(int j=1; j<=lb; j++){
            if(a[i-1] == b[j-1]) v[i][j] = v[i-1][j-1] + 1;
            else v[i][j] = max(v[i-1][j],v[i][j-1]);
        }
    }
    return v[la][lb];
}

int main(){
    int t; cin>>t;
    while(t--){
        vector<vector<int>> v(1001,vector<int>(1001,0));
        string a,b;
        getline(cin>>ws,a);
        getline(cin>>ws,b);
        cout<<dynamic(v,a,b,a.length(),b.length())<<endl;
    }
}