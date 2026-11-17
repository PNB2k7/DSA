#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *left, *right;
    int value;
};

void add(Node *&tree, int v){
    if(tree == NULL) {
        tree = new Node();
        tree -> value = v;
        return;
    }
    if(tree -> value > v) add(tree -> left, v);
    else add(tree->right,v);
}

void post(Node *tree){
    if(tree == NULL) return;
    post(tree -> left);
    post(tree -> right);
    cout<<tree->value<<" ";
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
        post(tree);
        cout<<endl;
    }
}