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

void InsertAtHead(node* &head, int val){
    node* n = new node(val);

    n->next=head;
    head=n;
}

void InsertAtTail(node* &head, int val){
    node* n = new node(val);

    node* temp = head;
    while(temp->next!=NULL){
        temp= temp->next;
    }

    temp->next=n;
}

void makecycle(node* &head, int pos){
    node* temp = head;
    node* startNode;

    int count = 1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }

    temp->next=startNode;
}

bool DetectionCycle(node* &head){
    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast){
            return true;
        }
    }
    return false;
}

void RemoveCycle(node* &head){
    // We have detected the cycle
    node* slow=head;
    node* fast = head;

    do{
        fast = fast->next->next;
        slow = slow->next;
    }while(slow!=fast);

    fast = head;
    while(fast->next != slow->next){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = NULL;
}

void display(node* head){
    
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
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
    InsertAtTail(head, 6);
    display(head);

    makecycle(head, 3);
    //  display(head);
    cout<<DetectionCycle(head)<<endl;
    cout<<">>>>>>>>>>Removing cycle<<<<<<<<<<"<<endl;
    RemoveCycle(head);
    cout<<DetectionCycle(head)<<endl;;
    display(head);

    return 0;
}