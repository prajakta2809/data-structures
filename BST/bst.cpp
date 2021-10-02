#include<bits/stdc++.h>
using namespace std;
struct Node {  
    int data;  
    Node *left;  
    Node *right;  
};  
Node* create(int item)  
{  
    Node* node = new Node;  
    node->data = item;  
    node->left = node->right = NULL;  
    return node;  
}  
  
void inorder(Node *root)  
{  
    if (root == NULL)  
        return;  
  
    inorder(root->left);  
    cout<< root->data << "   ";  
    inorder(root->right);  
}  
Node* findMinimum(Node* cur)  
{  
    while(cur->left != NULL) {  
        cur = cur->left;  
    }  
    return cur;  
}  
Node* insertion(Node* root, int item)  
{  
    if (root == NULL)  
        return create(item);  
    if (item < root->data)  
        root->left = insertion(root->left, item);  
    else  
        root->right = insertion(root->right, item);  
  
    return root;  
}  
  
void search(Node* &cur, int item, Node* &parent)  
{  
    while (cur != NULL && cur->data != item)  
    {  
        parent = cur;  
  
        if (item < cur->data)  
            cur = cur->left;  
        else  
            cur = cur->right;  
    }  
    
}  
  
void deletion(Node*& root, int item)  
{  
    Node* parent = NULL;  
    Node* cur = root;  
  
    search(cur, item, parent);  
    if (cur == NULL)  
        return;  
  
    if (cur->left == NULL && cur->right == NULL)  
    {  
        if (cur != root)  
        {  
            if (parent->left == cur)  
                parent->left = NULL;  
            else  
                parent->right = NULL;  
        }  
        else  
            root = NULL;  
  
        free(cur);       
    }  
    else if (cur->left && cur->right)  
    {  
        Node* succ  = findMinimum(cur->right);  
  
        int val = succ->data;  
  
        deletion(root, succ->data);  
  
        cur->data = val;  
    }  
  
    else  
    {  
        Node* child = (cur->left)? cur->left: cur->right;  
  
        if (cur != root)  
        {  
            if (cur == parent->left)  
                parent->left = child;  
            else  
                parent->right = child;  
        }  
  
        else  
            root = child;  
        free(cur);  
    }  
}  
  
int main()  
{  
   Node* root = NULL;  
   cout<<"Enter number of nodes: ";
   int n;
   cin>>n;
   int keys[n];  
   for(int i=0;i<n;i++)  
    {  
    cout << "Enter value to be inserted: ";  
    cin>>keys[i];  
        root = insertion(root, keys[i]);  
    }  
    cout<<"Performing inorder..."<<endl;
    inorder(root);  
    cout<<"Minimun element: "<<endl;
    Node* cur=findMinimum(root);
    cout<<cur->data<<endl;
    cout<<"\nEnter item you want to delete: ";
    int ItemDelete;
	cin>>ItemDelete;  
    deletion(root, ItemDelete);  
    inorder(root);  
    return 0;  
}  

