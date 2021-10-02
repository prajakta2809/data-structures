#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};

Node *deleteNodeOfASinglyLinkedList(Node *head,int n){
    Node *tmp=head,*pre=NULL;
    if(head->data==n){
        head = head->next;
        free(tmp);
        return head;
    }
    else{
        do{
            pre=tmp;
            tmp=tmp->next;
        }while(tmp->data!=n);
        pre->next = tmp->next;
        free(tmp);
        return head;
    }
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

    head = deleteNodeOfASinglyLinkedList(head,4);
    displaySinglyLinkedList(head);

    head = deleteNodeOfASinglyLinkedList(head,2);
    displaySinglyLinkedList(head);

    head = deleteNodeOfASinglyLinkedList(head,1);
    displaySinglyLinkedList(head);

    return 0;
}
