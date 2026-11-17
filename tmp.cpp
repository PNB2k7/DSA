#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node *left, *right;
};

void add(Node *&tree, vector<int> in, vector<int> pre){ 
    tree = new Node();
    tree->value = pre[0];
    int index = 0;
    while(in[index] != pre[0]) index++;
    vector<int> tmp_in, tmp_pre;
    for(int i=0; i<index; i++){
        tmp_in.push_back(in[i]);
        tmp_pre.push_back(pre[i+1]);
    }
    if(tmp_in.size()) add(tree->left, tmp_in, tmp_pre);
    tmp_in.clear(); tmp_pre.clear();
    for(int i=index+1; i<in.size(); i++){
        tmp_in.push_back(in[i]);
        tmp_pre.push_back(pre[i]);
    }
    if(tmp_in.size()) add(tree->right, tmp_in, tmp_pre);
}

void post(Node *tree){
    if(tree == NULL) return;
    post(tree->left);
    post(tree->right);
    cout<<tree->value<<" ";
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> pre(n),in(n);
        for(auto &x : in) cin>>x;
        for(auto &x : pre) cin>>x;
        Node *tree = new(Node);
        add(tree,in,pre);
        post(tree);
        cout<<endl;
    }
}