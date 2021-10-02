#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
};

Node *deleteAfterGivenNode(Node *head,int n) {
    if(head->data == n && head->next ==NULL){
        return head;
    }
    else if(head->data == n && head->next !=NULL){
        head->next = head->next->next;
        return head;
    }
    else{
        Node *tmp=head;
        while(tmp->data!=n){
            tmp=tmp->next;
        }
        if(tmp->next->next==NULL){
            tmp->next=NULL;
        }
        else{
            tmp->next=tmp->next->next;
        }
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
    head = deleteAfterGivenNode(head,4);

    displaySinglyLinkedList(head);
    head = deleteAfterGivenNode(head,9);

    displaySinglyLinkedList(head);
    head = deleteAfterGivenNode(head,2);

    displaySinglyLinkedList(head);

    return 0;
}
