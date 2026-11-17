#include<iostream>
#include<queue>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        queue<int> q;
        int n; cin>>n;
        while(n--){
            int k; cin>>k;
            switch(k){
                case 1:
                    cout<<q.size()<<endl;
                    break;
                case 2:
                    cout<<(q.empty()?"YES":"NO")<<endl;
                    break;
                case 3:
                    int tmp; cin>>tmp;
                    q.push(tmp);
                    break;
                case 4:
                    if(!q.empty()) q.pop();
                    break;
                case 5:
                    cout<<(q.empty()?-1:q.front())<<endl;
                    break;
                case 6:
                    cout<<(q.empty()?-1:q.back())<<endl;
                    break;
            }
        }
    }
}