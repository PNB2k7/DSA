#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node *left, *right;
};

void add(Node *&tree, int tmp){
    if(tree == NULL){
        tree = new Node();
        tree -> value = tmp;
        return;
    }
    if(tree -> value > tmp) add(tree ->left,tmp);
    else add(tree -> right,tmp);
}

void preorder(Node *&tree){
    if(tree == NULL) return;
    cout<<tree->value<<" ";
    preorder(tree->left);
    preorder(tree->right);
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        Node *tree = NULL;
        for(int i=0; i<n; i++){
            int tmp; cin>>tmp;
            add(tree,tmp);
        }
        preorder(tree);
        cout<<endl;
    }
}