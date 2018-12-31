#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};

class removeDups
{
    public:
    int dict[1000] = {0};
    
    void remove(node *head)
    {
        node *curr = head;
        node *prev = new node;
        while(curr!=NULL)
        {
            if(dict[curr->data] > 0)
            {
                prev->next = curr->next;
                
            }
            else
            {
                dict[curr->data] += 1;
                prev = curr;
            }
            
            curr = curr->next;
        }
        curr = head;
        while (curr!=NULL)
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
     removeDups obj;

    cout<<"Enter a value for linked list. Enter to stop";
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
        //cout<<"Curr : ";
       // cout<<curr->data;
       // cout<<"\n";
        if(parent!=NULL)
        {
            //cout<<"Parent : ";
            //cout<<parent->data;
            //cout<<"\n";
            parent->next = curr;
        }
        else
        {
            head = curr;
        }
        parent = curr;
        cin>>temp;
    }

    obj.remove(head);
}