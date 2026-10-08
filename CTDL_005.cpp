#include<iostream>
using namespace std;

struct ListNode{
    int value;
    ListNode *next;
};

int main(){
    int n; cin>>n;
    ListNode *head = new(ListNode), *cur = head;
    for(int i=0; i<n-1; i++){
        cin >> cur -> value;
        ListNode *newNode = new(ListNode);
        cur -> next = newNode;
        cur = newNode;
    }
    cin>> cur -> value;
    cur -> next = nullptr;

    int k; cin>>k;
    cur = head;

    while(cur -> next != nullptr){
        if (cur -> next -> value == k) {
            cur -> next = cur -> next -> next;
        }
        else cur = cur -> next;
    }

    if(head -> value == k) head = head -> next;

    cur = head;
    while(cur != nullptr){
        cout<< cur -> value <<" ";
        cur = cur -> next;
    }
}