#include<iostream>
#include<queue>
#include<sstream>
using namespace std;

int main(){
    queue<int> q;
    int n; cin>>n;
    while(n--){
        string s; getline(cin>>ws,s);
        if(s == "POP"){
            if(!q.empty()) q.pop();
        }
        else if(s == "PRINTFRONT"){
            if(q.empty()) cout<<"NONE\n";
            else cout<<q.front()<<endl;
        }
        else{
            stringstream ss(s);
            string word;
            ss>>word;
            ss>>word;
            q.push(stoi(word)); 
        }
    }
}