#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};

void insertNewNodeAtEnd(Node *head,int n){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = NULL;

    Node *temp=head;
    if(head==NULL){
        head = newNode;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
}

void displaySinglyLinkedList(Node *head){
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}

int main(){
    Node *head=NULL,*last=NULL,*newNode=NULL;
    for(int i=0;i<5;i++){
        newNode= (Node*)malloc(sizeof(Node));
        newNode->data = i+1;
        newNode->next = NULL;
        if(!head){
            head = newNode;
        }
        else{
            last->next = newNode;
        }
        last = newNode;
    }

    insertNewNodeAtEnd(head,100);
    displaySinglyLinkedList(head);
    insertNewNodeAtEnd(head,700);
    displaySinglyLinkedList(head);
    insertNewNodeAtEnd(head,200);
    displaySinglyLinkedList(head);
    return 0;
}
