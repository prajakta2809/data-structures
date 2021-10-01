#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};

bool searchForValue(Node *head,int n){
    Node *temp = head;
    while(temp){
        if(temp->data==n){
            return true;
        }
        temp=temp->next;
    }
    return false;
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


//    int value = 60;
    int value = 601;
    bool isPresent = searchForValue(head,value);
    if(isPresent){
        cout<<value<<" is present in Linked List"<<endl;
    }
    else{
        cout<<value<<" is not present in Linked List"<<endl;
    }


    return 0;
}
