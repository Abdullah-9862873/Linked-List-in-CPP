#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int val){
            data = val;
            next = NULL; 
        }
};

node* reverse(node* &head){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}

node* revereRecursive(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead= revereRecursive(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
}

node* reverseK(node* &head, int k){

    node* prevptr= NULL;
    node* currptr = head;
    node* nextptr;

    int count=0;
    while(currptr!=NULL || count<k){
        nextptr = currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
        count++;
    }

    head->next= reverseK(nextptr, k);

    return prevptr;

}

int main(){


    return 0;
}