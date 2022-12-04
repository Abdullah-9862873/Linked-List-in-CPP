#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    //Constructor to initialise value of node
    node(int val){
        data = val;
        next = NULL;
    }
};

void InsertAtTail(node* &head, int val){
    
    //Making new node
    node* n = new node(val);

    // if head has nothing that is linked list is empty
    if(head==NULL){
        head =n;
        return;
    }

    //Traversing from head to last
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    // Inserting n node at last
    temp->next=n;
    
}

void InsertAtHead(node* &head, int val){
    node* n = new node(val);

    n->next=head;
    head=n;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL;
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    display(head);
    InsertAtHead(head, 4);
    display(head);

    return 0;
}