#include<iostream>
using namespace std;
struct node{
    string data;
    node *next;
};
class deleteNode
{
    public:
    void method1(node *temp)
    {
        temp->data = temp->next->data;
        temp->next = temp->next->next;
    }
};
int main()
{
    string temp;
    deleteNode obj;
    int k;
    cout<<"Enter a value for linked list. Enter quit to stop";
    node *parent = new node;
    parent = NULL;
    node *head = new node;
    cin>>temp;
    while(temp!="quit")
    {
        node *curr = new node;
        curr->data = temp;
        curr->next = NULL;
        if(parent!=NULL)
        {
            parent->next = curr;
        }
        else
        {
            head = curr;
        }
        parent = curr;
        cin>>temp;
    }
    string str;
    cout<<"Enter node value to be deleted: ";
    cin>>str;
    node *curr = head;
    while(curr->data!=str)
    {
        curr=curr->next;
    }
    obj.method1(curr);
    curr = head;
    while(curr!=NULL)
    {
        cout<<curr->data;
        curr=curr->next;
        cout<<"->";
    }
    cout<<"NULL";
    cout<<"\n";
}