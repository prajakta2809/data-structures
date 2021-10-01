#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};

void displaySinglyLinkedList(Node *head){
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return;
}

int main(){
    Node *head=NULL,*last=NULL,*newNode=NULL;
    for(int i=0;i<100;i++){
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


    return 0;
}
