#include<iostream>
#include<cmath>
using namespace std;
struct node
{
    node *next;
    int data;
};

class sumlists
{
    public:
    node* solution1(node *head1, node *head2)
    {
        node* curr1 = head1;
        node* curr2 = head2;
        int sum1 = 0, sum2 = 0;
        int i = 0;
        while(curr1 != NULL)
        {
            sum1 = sum1 + curr1->data*(pow(10,i));
            curr1 = curr1->next;
            i++;
        }
        i = 0;
        while(curr2 != NULL)
        {
            sum2 = sum2 + curr2->data*(pow(10,i));
            curr2 = curr2->next;
            i++;
        }
        int totsum = sum1 + sum2;
        node *prev = new node;
        node *head = new node;
        head = NULL;
        while(totsum!=0)
        {
            node *curr3 = new node;
            int num = totsum %10;
            curr3->data = num;
            curr3->next = NULL;
            if(head == NULL)
                head= curr3;
            else
                prev->next = curr3;
            prev = curr3;
            totsum = totsum/10;
        }
        return head;
    }


    node* solution2(node *head1, node *head2)
    {
        node* curr1 = head1;
        node* curr2 = head2;
        int sum1 = 0, sum2 = 0;
        while(curr1 != NULL)
        {
            sum1 = sum1*10 + curr1->data;
            curr1 = curr1->next;
        }
        while(curr2 != NULL)
        {
            sum2 = sum2*10 + curr2->data;
            curr2 = curr2->next;
        }
        int totsum = sum1 + sum2;
        node *prev = new node;
        prev = NULL;
        node *head = new node;
        while(totsum!=0)
        {
            node *curr3 = new node;
            int num = totsum %10;
            curr3->data = num;
            curr3->next = prev;
            prev = curr3;
            totsum = totsum/10;
        }
        head = prev;
        return head;
    }
};

int main()
{
    string temp1,temp2;
    sumlists obj;
    cout<<"Enter a value for linked list. Enter quit to stop";
    node *parent = new node;
    parent = NULL;
    node *head1 = new node;
    cin>>temp1;
    while(temp1!="quit")
    {
        int val = atoi(temp1.c_str());
        node *curr = new node;
        curr->data = val;
        curr->next = NULL;
        if(parent!=NULL)
        {
            parent->next = curr;
        }
        else
        {
            head1 = curr;
        }
        parent = curr;
        cin>>temp1;
    }

    parent = NULL;
    node *head2 = new node;
    cin>>temp2;
    while(temp2!="quit")
    {
        int val = atoi(temp2.c_str());
        node *curr = new node;
        curr->data = val;
        curr->next = NULL;
        if(parent!=NULL)
        {
            parent->next = curr;
        }
        else
        {
            head2 = curr;
        }
        parent = curr;
        cin>>temp2;
    }
    node *curr1 = obj.solution1(head1,head2);
    while(curr1!=NULL)
    {
        cout<<curr1->data;
        cout<<"->";
        curr1 = curr1->next;
    }
    cout<<"NULL";
    cout<<"\n";
    node *curr2 = obj.solution2(head1,head2);
    while(curr2!=NULL)
    {
        cout<<curr2->data;
        cout<<"->";
        curr2 = curr2->next;
    }
    cout<<"NULL";
    cout<<"\n";
}