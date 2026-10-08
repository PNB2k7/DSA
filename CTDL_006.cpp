#include<iostream>
using namespace std;

struct List{
    int value;
    List *next;
};

int main(){
    int n; cin>>n;
    List *First = new(List);
    List *cur = First;
    for(int i=0; i<n-1; i++){
        cin>> cur-> value;
        cur -> next = new(List);
        cur = cur -> next;
    }
    cin >> cur -> value;
    cur -> next = nullptr;
    
    cur = First;
    while(cur != nullptr){
        List *pre = cur, *l = cur -> next;
        while(l!=nullptr){
            if(l -> value == cur -> value){
                pre -> next = l -> next;
                l = pre -> next;
            }
            else{
                pre = pre -> next;
                l = l-> next;
            }
        }
        cur = cur -> next;
    }

    cur = First;
    while(cur != nullptr){
        cout<< cur -> value << " ";
        cur = cur -> next;
    }
}