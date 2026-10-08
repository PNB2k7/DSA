#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        for(auto &x : v) cin>>x;
        sort(v.begin(),v.end());
        int tmp = v[0] + v[n-1], m = tmp;
        int i = 0, j = n-1;
        while(j - i > 1){
            if(tmp == 0) break;
            else if(tmp > 0){
                tmp = tmp - v[j] + v[j-1];
                j--;
                if(abs(tmp) < abs(m)) m = tmp;
                if(abs(tmp) == abs(m) && tmp < m) m = tmp;
            }
            else{
                tmp = tmp - v[i] + v[i+1];
                i++;
                if(abs(tmp) < abs(m)) m = tmp;
                if(abs(tmp) == abs(m) && tmp < m) m = tmp;
            }
        }
        cout<<m<<endl;
    }
}