#include <iostream>
#include <cstdlib>
using namespace std;

class Node{
public:
    int data;
    Node *next;
} *head=NULL,*lastNode=NULL;

Node *insertNewNodeAtTheEnd(int n){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = head;
    lastNode->next = newNode;
    lastNode = newNode;
    return head;
}


void displayCircularLinkedList(){
    if(head ==NULL){
        return;
    }
    else{
        Node *tmp=head;
        do{
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }while(tmp!=head);
    }
    cout<<endl;
    return;
}

int main()
{
    /****************Creating Circular Linked List*******************/
    cout<<"Creating Circular Linked List......."<<endl;
    Node *newNode=NULL;
    for(int i=0;i<10;i++){
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = NULL;
        if(head==NULL){
            head=newNode;
            head->next=head;
            lastNode = head;
        }
        else{
            newNode->next=head;
            lastNode->next = newNode;
            lastNode = newNode;
        }
    }
    /****************Created Circular Linked List*******************/

    displayCircularLinkedList();

    head = insertNewNodeAtTheEnd(1);
    displayCircularLinkedList();

    head = insertNewNodeAtTheEnd(10);
    displayCircularLinkedList();

    head = insertNewNodeAtTheEnd(100);
    displayCircularLinkedList();

    return 0;
}
