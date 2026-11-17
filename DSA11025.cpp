#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node *left, *right;
};

void build(vector<int> &v, int l, int r, Node *&tree){
    if(l>r) return;
    tree = new Node();
    int mid = (r+l)/2;
    tree -> value = v[mid];
    build(v,l,mid-1,tree->left);
    build(v,mid+1,r,tree->right);
}

void pre(Node *tree){
    if(tree == NULL) return;
    cout<<tree->value<<" ";
    pre(tree->left);
    pre(tree->right);
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        for(auto &x : v) cin>>x;
        sort(v.begin(), v.end());
        Node *tree = NULL;
        build(v,0,n-1,tree);
        pre(tree);
        cout<<endl;
    }
}