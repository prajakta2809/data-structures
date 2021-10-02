#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
};

Node *deleteEndNode(Node *head) {
    if(head==NULL) {
        return head;
    }
    else if(head->next==NULL) {
        return NULL;
    }
    else {
        Node *tmp=head;
        while(tmp->next->next!=NULL) {
            tmp=tmp->next;
        }
        tmp->next=NULL;
    }
    return head;
}

void displaySinglyLinkedList(Node *head) {
    Node *temp = head;
    while(temp) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}

int main() {
    Node *head=NULL,*last=NULL,*newNode=NULL;
    for(int i=0; i<10; i++) {
        newNode= (Node*)malloc(sizeof(Node));
        newNode->data = i+1;
        newNode->next = NULL;
        if(!head) {
            head = newNode;
        } else {
            last->next = newNode;
        }
        last = newNode;
    }

    displaySinglyLinkedList(head);
    head = deleteEndNode(head);

    displaySinglyLinkedList(head);
    head = deleteEndNode(head);

    displaySinglyLinkedList(head);
    head = deleteEndNode(head);

    displaySinglyLinkedList(head);

    return 0;
}
