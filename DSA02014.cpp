#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

bool flag = true, flagtmp = false;

void part(const string &s, vector<string> &search){
    stringstream ss(s);
    string word;
    while(ss >> word) search.push_back(word);
    sort(search.begin(), search.end());
}

void Try(const vector<vector<char>> &matrix, const string &f, vector<vector<int>> &mark, pair<int,int> pos = {0,0}, int inf = 0){
    if(flagtmp) return;
    if(inf == f.length()) {
        cout<<f<<" ";
        flag = false; flagtmp = true;
        return;
    }
    if(pos.first < 0 || pos.first >= matrix.size() || pos.second < 0 || pos.second >= matrix[0].size()) return;
    if(matrix[pos.first][pos.second] != f[inf] || mark[pos.first][pos.second]) return;
    mark[pos.first][pos.second] = 1;
    for(int i = pos.first - 1; i <= pos.first + 1; i++){
        for(int j=pos.second - 1; j <= pos.second + 1; j++){
            if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) continue;
            Try(matrix,f,mark,{i,j},inf+1);
        }
    }
    mark[pos.first][pos.second] = 0;
}

int main(){
    int t; cin>>t;
    while(t--){
        int k,m,n; cin>>k>>m>>n;
        vector<string> search;
        vector<vector<char>> matrix(m, vector<char>(n));
        vector<vector<int>> mark(m,vector<int>(n,0));
        string s; getline(cin>>ws,s);
        part(s,search);
        for(auto &x : matrix){
            for(auto &y : x) cin>>y;
        }
        for(auto &x : search){
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    Try(matrix,x,mark,{i,j});
                    if(flagtmp) break;
                }
                if(flagtmp) break;
            }
            flagtmp = false;
        }
        if(flag) cout<<-1;
        flag = true;
        cout<<endl;
    }
}