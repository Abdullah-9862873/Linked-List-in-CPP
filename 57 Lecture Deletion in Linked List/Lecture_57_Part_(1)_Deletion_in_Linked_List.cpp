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

void InsertAtTail(node* &head, int val){
    node* n = new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node* temp =head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=n;
}

void InsertAtHead(node* &head, int val){
    node* n = new node(val);

    n->next=head;
    head=n;
}

void DeleteAtHead(node* &head){
    node* todelete = head;

    head = head->next;
    delete todelete;
}

void Deletion(node* &head, int val){

    if(head==NULL){
        return;
    }
    
    if(head->next==NULL){
        DeleteAtHead(head);
        return;
    }

    node* n = new node(val);

    node* temp = head;
    while(temp->next->data!=val){
        temp= temp->next;
    }
    // To get the element that we deleted
    node* deleted_element = temp->next;
    // To point (n-1)th next to (n+1)th val 
    temp->next=temp->next->next;

    delete deleted_element;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL;
    InsertAtHead(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    display(head);

    cout<<"After deleting"<<endl;
    Deletion(head, 4);
    display(head);

    DeleteAtHead(head);
    display(head);


    return 0;
}