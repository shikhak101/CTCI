#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
class kthtolast
{
    public:
    node* method1(node *head,int k)
    {
        int count = 1;
        node *curr = head;
        while(count < k)
        {
            curr = curr->next;
            count++;
        }
        return curr;
    }
};
int main()
{
    string temp;
    kthtolast obj;
    int k;
    cout<<"Enter a value for linked list. Enter quit to stop";
    node *parent = new node;
    parent = NULL;
    node *head = new node;
    cin>>temp;
    while(temp!="quit")
    {
        int val = atoi(temp.c_str());
        node *curr = new node;
        curr->data = val;
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
    cout<<"Enter k value : ";
    cin>>k;
    node *tempnode = obj.method1(head,k);
    
    while(tempnode!=NULL)
    {
        cout<<tempnode->data;
        cout<<"->";
        tempnode = tempnode->next;
    }
    cout<<"NULL";
    cout<<"\n";
}