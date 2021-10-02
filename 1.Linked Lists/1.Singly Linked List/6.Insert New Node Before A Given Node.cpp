#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
};

Node* insertNodeBeforeGivenNode(Node* head,int beforeNodeValue,int n) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data= n;
    newNode->next = NULL;
    if(head->data==beforeNodeValue) {
        newNode->next = head;
        return newNode;
    } else {
        Node *tmp = head,*prev=NULL;
        do {
            prev = tmp;
            tmp=tmp->next;

        } while(tmp->data!=beforeNodeValue);
        newNode->next = tmp;
        prev->next = newNode;

    }
    return head;
}

void displaySinglyLinkedList(Node *head) {
    Node *temp = head;
    while(temp) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
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
    cout<<endl;
    head = insertNodeBeforeGivenNode(head,5,100);//before 5 we are inserting 100
    displaySinglyLinkedList(head);
    cout<<endl;
    head = insertNodeBeforeGivenNode(head,100,2);//before 100 we are inserting 2
    displaySinglyLinkedList(head);
    cout<<endl;
    head = insertNodeBeforeGivenNode(head,10,9);//before 10 we are inserting 9
    displaySinglyLinkedList(head);
    cout<<endl;

    return 0;
}
