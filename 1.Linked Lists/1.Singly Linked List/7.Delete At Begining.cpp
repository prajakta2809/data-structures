#include<iostream>
#include<cstdlib>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};

Node* deleteElementFromBeg(Node *head){
    Node *tmp=head;
    if(head == NULL){
        return head;
    }
    else if(head->next==NULL){
        return NULL;
    }
    head = head->next;
    free(tmp);
    return head;
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
    for(int i=0;i<10;i++){
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

    displaySinglyLinkedList(head);
    head = deleteElementFromBeg(head);

    displaySinglyLinkedList(head);
    head = deleteElementFromBeg(head);

    displaySinglyLinkedList(head);
    head = deleteElementFromBeg(head);

    displaySinglyLinkedList(head);
    head = deleteElementFromBeg(head);

    displaySinglyLinkedList(head);

    return 0;
}
