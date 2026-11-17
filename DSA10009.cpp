#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> Floyd(vector<vector<int>> matrix, int n){
    vector<vector<int>> tmp;
    for(int k=0; k<n; k++){
        tmp = matrix;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = min(tmp[i][j], tmp[i][k] + tmp[k][j]);
            }
        }
    }
    return matrix;
}

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(n,1e7));
    for(int i=0; i<n; i++) matrix[i][i] = 0;
    for(int i=0; i<m; i++){
        int a,b,c; cin>>a>>b>>c;
        matrix[a-1][b-1] = c;
        matrix[b-1][a-1] = c;
    }
    matrix = Floyd(matrix,n);
    int q; cin>>q;
    while(q--){
        int a,b; cin>>a>>b;
        cout<<matrix[a-1][b-1]<<endl;
    }
}