#include<iostream>
#include<string>
#include<vector>
using namespace std;

void retry(vector<int> check, int size, vector<int> res = {}){
    for(int i=0; i < 10; i++){
        if(check[i] == 1){
            res.push_back(i);
            check[i] = 0;
            if(res.size() == size){
                for(auto x : res){
                    cout<<char(x+65);
                }
                cout<<" ";
            }
            else retry(check,size,res);
            check[i] = 1;
            res.pop_back();
        }
    }
}

//65 - 74
int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        vector<int> check(10,0);
        for(auto &x: s){
            check[x-65]++;
        }
        retry(check,s.length());
        cout<<endl;  
    }
}