#include<iostream>
using namespace std;
struct node
{
    node *next;
    int data;
};

class partition1
{
    public:
    void method1(node* head,int val)
    {
        node *curr = head;
        node *prev = new node;
        prev = NULL;
        node *newhead = new node;
        while(curr!=NULL)
        {
            if(curr->data < val)
            {
                node *temp = new node;
                temp->data = curr->data;
                temp->next = NULL;
                if (prev == NULL)
                {
                    prev = temp;
                    newhead = temp;
                }
                else
                {
                    prev->next = temp;
                    prev = temp;
                }
            }
            curr= curr->next;
        }
        curr = head;
        while(curr!=NULL)
        {
            if(curr->data >= val)
            {
                node *temp = new node;
                temp->data = curr->data;
                temp->next = NULL;
                if (prev == NULL)
                {
                    prev = temp;
                    newhead = temp;
                }
                else
                {
                    prev->next = temp;
                    prev = temp;
                }
            }
            curr= curr->next;
        }
        curr = newhead;
        while(curr!=NULL)
        {
            cout<<curr->data;
            cout<<"->";
            curr = curr->next;
        }
        cout<<"NULL";
        cout<<"\n";
    }
};

int main()
{
    string temp;
    partition1 obj;
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
    int part;
    cout<<"Enter partition value: ";
    cin>>part;
    obj.method1(head,part);
}