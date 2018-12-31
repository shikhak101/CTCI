#include<iostream>
#include<cmath>
using namespace std;
struct node
{
    node *next;
    int data;
};

class stackmin
{
    public:
    node* push(node *head,int str)
    {
        node *temp = new node;
        temp->data = str;
        temp->next = head;
        head = temp;
        return head;
    }
    node* pop(node *head)
    {
        head = head->next;
        return head;
    }
    int findmin(node *head)
    {
        int a;
        int min = 100000;
        cout<<"Enter value : ";
        cin>>a;
        while(a!=-1)
        {
            head = push(head,a);
            if(a<min) min = a;
            cin>>a;
        }
        
        return min;
    }
};

int main()
{
    stackmin obj;
    node *head = new node;
    cout<<"Enter int";
    int i = 0;
    cin>>i;
    if(i==1)
    {
        cout<<"Enter value to push : ";
        int str;
        cin>>str;
        head = obj.push(head,str);
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
    else if(i==2)
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
    else if(i==3)
    {
        head =NULL;
        int result = obj.findmin(head);
        cout<<result;
    }
    
}