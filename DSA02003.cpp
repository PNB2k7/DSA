#include<iostream>
#include<vector>
#include<string>
using namespace std;
int count;

void findPath(int a[10][10], int n, int x=0, int y=0, string s=""){
    if(a[0][0] == 0) return;
    if(x == n || y == n) return;
    if(x==n-1 && y==n-1){
        cout<<s<<" ";
        count++;
        return;
    }
    if(x!=n-1 && a[x+1][y]==1){
        findPath(a,n,x+1,y,s+'D');
    }
    if(y!= n-1 && a[x][y+1]==1){
        findPath(a,n,x,y+1,s+'R');
    }
    return;
}

int main(){
    int t; cin>>t;
    while(t--){
        count = 0;
        int n; cin>>n;
        int a[10][10];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) cin>>a[i][j];
        }
        findPath(a,n);
        if(count==0) cout<<-1;
        cout<<endl;
    }
}