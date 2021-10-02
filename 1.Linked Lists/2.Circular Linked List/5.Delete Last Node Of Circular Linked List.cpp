#include <iostream>
#include <cstdlib>
using namespace std;

class Node{
public:
    int data;
    Node *next;
} *head=NULL,*lastNode=NULL;

Node *deleteLastNode(){
    Node *tmp = head,*tmp2=NULL;
    while(tmp->next!=lastNode){
        tmp=tmp->next;
    }
    lastNode = tmp;
    tmp2 = lastNode->next;
    lastNode->next = lastNode->next->next;
    free(tmp2);
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

    head = deleteLastNode();
    displayCircularLinkedList();

    head = deleteLastNode();
    displayCircularLinkedList();

    head = deleteLastNode();
    displayCircularLinkedList();

    return 0;
}
