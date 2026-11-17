#include<iostream>
#include<vector>
using namespace std;

void next(vector<int> &v){
    while(true){
        cout<<"(";
        for(int i=0; i<v.size(); i++){
            cout<<v[i];
            if(i != v.size()-1) cout<<" ";
        }
        cout<<") ";
        int k = v.size()-1;
        while(k>0 && (v[k-1] > v[k] || v[k] == 1)) k--;
        if(k == 0){
            if(v[0] == 1) break;
            else {
                if(v[0] - v[0+1] > 1){
                    v[0]--;
                    v[0+1]++;
                }
                else{
                    v[0]--;
                    v.push_back(1);
                }
            }
        }
        else{
            if(v[k] - v[k+1] > 1){
                v[k]--;
                v[k+1]++;
            }
            else{
                v[k]--;
                v.push_back(1);
            }
        }
    }
    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        vector<int> v(1);
        cin>>v[0];
        next(v);
    }
}