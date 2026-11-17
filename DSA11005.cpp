#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

struct Node{
    int value;
    Node *left, *right;
};

void findlevel(vector<int> &res, vector<int> tin, vector<int> level){
    set<int> stin(tin.begin(), tin.end()), slevel(level.begin(), level.end());
    for(auto &x : level){
        if(stin.find(x) != stin.end() && slevel.find(x) != slevel.end()) res.push_back(x);
    }
}

void add(Node *&tree, vector<int> &in, vector<int> &level){
    tree = new Node();
    tree->value = level[0];
    level.erase(level.begin());
    int index = 0;
    vector<int> tin,tlevel;
    while(index < in.size() && in[index] != tree->value) tin.push_back(in[index++]);
    findlevel(tlevel,tin,level);
    if(index < in.size() && tin.size() ) {
        add(tree->left,tin,tlevel);
    } 
    tin.clear();
    tlevel.clear();
    for(int i=index+1; i<in.size(); i++){
        tin.push_back(in[i]);
    }
    findlevel(tlevel,tin,level);
    if(tin.size()) add(tree->right,tin,tlevel);   
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
        vector<int> in(n),level(n);
        for(auto &x : in) cin>>x;
        for(auto &x : level) cin>>x;
        Node *tree;
        add(tree,in,level);
        post(tree);
        cout<<endl;
    }
}