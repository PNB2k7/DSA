#include <bits/stdc++.h>
using namespace std;

int n;
vector<char> s;
bool check = true;

void Try(vector<vector<int>>& v, vector<vector<bool>>& b, int i, int j, pair<int, int> p = {n - 1, n - 1}){
    if(i == p.first && j == p.second){
        for(int i = 0; i < s.size(); i++) cout << s[i];
        cout << " ";
        check = false;
        return;
    }

    if(i < n-1 && v[i+1][j] == 1){
        if(!b[i+1][j]){
            s.push_back('D');
            b[i+1][j] = true;
            Try(v, b, i+1, j);
            s.pop_back();
            b[i+1][j] = false;
        }
        
    }

    if(j > 0 && v[i][j-1] == 1){
        if(!b[i][j-1]){
            b[i][j-1] = true;
            s.push_back('L');
            Try(v, b, i, j-1);
            s.pop_back();
            b[i][j-1] = false;
        }
    }
     
    if(j < n-1 && v[i][j+1] == 1){
        if(!b[i][j+1]){
            s.push_back('R');
            b[i][j+1] = true;
            Try(v, b, i, j+1);
            s.pop_back();
            b[i][j+1] = false;
        }
    }

    if(i > 0 && v[i-1][j] == 1){
        if(!b[i-1][j]){
            b[i-1][j] = true;
            s.push_back('U');
            Try(v, b, i-1, j);
            s.pop_back();
            b[i-1][j] = false;
        }
    }
}

int main(){ 
    int t; cin >> t;
    while(t--){
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n));
        vector<vector<bool>> b(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> v[i][j];
            }
        }
        check = true;
        s.clear();

        if(v[0][0] == 1){
            vector<vector<bool>> b(n, vector<bool>(n, false));
            b[0][0] = true;
            Try(v, b, 0, 0);
        }
        
        if(check) cout << -1;
        cout<<endl;
    }
}
