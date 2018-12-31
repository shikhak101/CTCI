#include<iostream>
#include<cmath>
using namespace std;
struct node
{
    node *next;
    string data;
};

class sortstack
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
    string top(node *temp)
    {
        return temp->data;
    }
    node* sorting(node *head)
    {
        node *sorthead = new node;
        sorthead = NULL;
        node *curr = head;
        while(curr!=NULL)
        {
            string val = top(curr);
            curr = pop(curr);
            if(sorthead == NULL)
            {
                sorthead = push(sorthead,val);
            }
            else
            {
                int count = 0;
                while(sorthead !=NULL && top(sorthead) < val)
                {
                    curr = push(curr,top(sorthead));
                    sorthead = pop(sorthead);
                    count++;
                }
                sorthead = push(sorthead,val);
                while(count>0 && curr != NULL)
                {
                    count--;
                    sorthead = push(sorthead,top(curr));
                    curr = pop(curr);
                }
            }
        }
        return sorthead;
    }
};

int main()
{
    sortstack obj;
    node *head = new node;
    head = NULL;
    int i = 0;
    while(i != -1)
    {
        cout<<"Press 1 to push, 2 to pop, 3 to sort, -1 to end : ";
        
        cin>>i;
        if(i == 1)
        {
            string a;
            cout<<"Enter value : ";
            cin>>a;
            head = obj.push(head,a);
            node *curr = head;
            while(curr!=NULL)
            {
                cout<<curr->data;
                cout<<"->";
                curr = curr->next;
            }
            cout<<"NULL";
            cout<<"\n";
        }
        if(i == 2)
        {
            head = obj.pop(head);
            node *curr = head;
            while(curr!=NULL)
            {
                cout<<curr->data;
                cout<<"->";
                curr = curr->next;
            }
            cout<<"NULL";
            cout<<"\n";
        }
        if(i == 3)
        {
            head = obj.sorting(head);
            node *curr = head;
            while(curr!=NULL)
            {
                cout<<curr->data;
                cout<<"->";
                curr = curr->next;
            }
            cout<<"NULL";
            cout<<"\n";
        }
    }

}