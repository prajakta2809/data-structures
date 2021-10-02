#include<iostream>
#include<cstdlib>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};

void insertNodeAfterGivenNode(Node *head,int givenValue,int n){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = NULL;

    if(head->next==NULL && head->data==givenValue){
        head->next=newNode;
    }
    else{
        Node *temp=head;
        while(temp){
            if(temp->data==givenValue){
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp=temp->next;
        }
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

    insertNodeAfterGivenNode(head,3,100);
    displaySinglyLinkedList(head);
    insertNodeAfterGivenNode(head,1,700);
    displaySinglyLinkedList(head);
    insertNodeAfterGivenNode(head,100,200);
    displaySinglyLinkedList(head);

    return 0;
}
