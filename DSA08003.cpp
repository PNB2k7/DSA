#include<iostream>
#include<deque>
#include<sstream>
using namespace std;

int main(){
    deque<int> q;
    int n; cin>>n;
    while(n--){
        string s, word; getline(cin>>ws,s);   
        stringstream ss(s);
        ss>>word;
        if(word == "PUSHBACK"){
            ss>>word;
            q.push_back(stoi(word));
        }
        else if(word == "PUSHFRONT"){
            ss>>word;
            q.push_front(stoi(word));
        }
        else if(word == "PRINTBACK"){
            if(!q.empty()) cout<<q.back()<<endl;
            else cout<<"NONE\n";
        }
        else if(word == "PRINTFRONT"){
            if(!q.empty()) cout<<q.front()<<endl;
            else cout<<"NONE\n";
        }
        else if(word == "POPFRONT"){
            if(!q.empty()) q.pop_front();
        }
        else{
            if(!q.empty()) q.pop_back();
        }
    }
}