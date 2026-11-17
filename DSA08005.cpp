#include<iostream>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s = "0";
        while(n--){
            int carry = 1, index = 0;
            while(carry && index < s.length()){
                if(s[index] == '0'){
                    s[index] = '1';
                    carry = 0;
                }
                else{
                    s[index++] = '0';
                }
            }
            if(carry) s.push_back('1');
            for(int i=s.length()-1; i>=0; i--) cout<<s[i];
            cout<<" ";
        }
        cout<<endl;
    }
}