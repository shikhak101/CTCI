#include<iostream>
#include<cmath>
using namespace std;
struct node
{
    node *next;
    string data;
};

class queueusingstack
{
    public:
    node* push(node *head, string str)
    {
        node *temp = new node;
        temp->data = str;
        temp->next = head;
        head = temp;
        return head;
    }
    node* pop(node *head)
    {
        if(head == NULL)
        {
            cout<<"Nothing present";
        }
        else
        {
            head = head->next;
        }
        return head;
    }
};

int main()
{
    node *head = new node;
    head = NULL;
    
    queueusingstack obj;
    int i = 0;
    int check = 0;
    while(i!=-1)
    {
        cout<<"Enter 1 to push, 2 to pop, -1 to exit : ";
        cin>>i;
        if(i==1)
        {
            if(check == 2 && head!=NULL)
            {
                node *temp = new node;
                node *head2 = new node;
                head2 = NULL;
                temp = head;
                while(head!=NULL)
                {
                    if(head2 == NULL)
                    {
                        node *n = new node;
                        n->data = head->data;
                        n->next = NULL;
                        head2 = n;
                    }
                    else{
                        node *n = new node;
                        n->data = head->data;
                        n->next = head2;
                        head2 = n;
                    }
                    head = head->next;
                }
                head = head2;
            }
            check = 1;
            string str;
            cout<<"Enter value : ";
            cin>>str;
            head = obj.push(head,str);
            node *curr = head;
            while(curr!=NULL)
            {
                cout<<curr->data;
                cout<<"->";
                curr=curr->next;
            }
            cout<<"NULL";
            cout<<"\n";
        }
        if(i==2)
        {
            if(check == 1 && head!=NULL)
            {
                node *head1 = new node;
                head1 = NULL;
                node *temp = new node;
                temp = head;
                // while(temp!=NULL)
                // {
                //     node *rev = new node;
                //     if(head1==NULL)
                //     {
                //         head1->data = temp->data;
                //         head1->next = NULL;
                //         temp = temp->next;
                //     }
                //     else{
                //         rev->data = temp->data;
                //         rev->next = head1;
                //         head1=rev;
                //         temp = temp->next;
                //     }
                // }
                while(head!=NULL)
                {
                    if(head1 == NULL)
                    {
                        node *n = new node;
                        n->data = head->data;
                        n->next = NULL;
                        head1 = n;
                    }
                    else{
                        node *n = new node;
                        n->data = head->data;
                        n->next = head1;
                        head1 = n;
                    }

                    head = head->next;
                }
                head = head1;
            }
            
            head = obj.pop(head);
            node *curr = head;
            while(curr!=NULL)
            {
                cout<<curr->data;
                cout<<"->";
                curr=curr->next;
            }
            cout<<"NULL";
            cout<<"\n";
            check = 2;
        }
    }
    
}