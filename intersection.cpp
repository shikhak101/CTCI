#include<iostream>
#include<cmath>
using namespace std;
struct node
{
    node *next;
    string data;
};

class intersection
{
    public:
    node* solution(node *head1, node *head2)
    {
        node *curr1 = head1;
        node *curr2 = head2;
        int len1 = 0;
        int len2 = 0;
        while(curr1!=NULL)
        {
            curr1 = curr1->next;
            len1++;
        }
        while(curr2!=NULL)
        {
            curr2 = curr2->next;
            len2++;
        }
        curr1 = head1;
        int diff = 0;
        int finallen = 0;
        if(len1>len2)
        {
            diff = len1 - len2;
            finallen = len2;
        }  
        else
        {
            diff = len2 - len1;
            finallen = len1;
        }
            
        while(diff > 0)
        {
            diff--;
            curr1 = curr1->next;
        }
        curr2 = head2;
        while(curr1!=NULL && curr2!=NULL)
        {
            if(curr1!=curr2){
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            else{
                return curr1;
            }
        }
        return NULL;
    }
};

int main()
{
    string temp1,temp2;
    intersection obj;

    node *head1 = new node;
    node *head2 = new node;
    node *curr1 = new node;
    node *curr2 = new node;
    node *curr3 = new node;
    node *curr4 = new node;
    node *curr5 = new node;
    node *curr6 = new node;
    head1->data = 'a';
    head1->next = curr1;
    curr1->data = 'b';
    curr1->next = curr2;
    curr2->data = 'c';
    curr2->next = curr3;
    curr3->data = 'd';
    curr3->next = curr4;
    curr4->data = 'e';
    curr4->next = curr5;
    curr5->data = 'f';
    curr5->next = NULL;
    head2->data ='1';
    head2->next = curr6;
    curr6->data = '2';
    curr6->next = curr3;

    // cout<<"Enter a value for linked list. Enter quit to stop";
    // node *parent = new node;
    // parent = NULL;
    // node *head1 = new node;
    // cin>>temp1;
    // while(temp1!="quit")
    // {
    //     int val = atoi(temp1.c_str());
    //     node *curr = new node;
    //     curr->data = val;
    //     curr->next = NULL;
    //     if(parent!=NULL)
    //     {
    //         parent->next = curr;
    //     }
    //     else
    //     {
    //         head1 = curr;
    //     }
    //     parent = curr;
    //     cin>>temp1;
    // }

    // parent = NULL;
    // node *head2 = new node;
    // cin>>temp2;
    // while(temp2!="quit")
    // {
    //     int val = atoi(temp2.c_str());
    //     node *curr = new node;
    //     curr->data = val;
    //     curr->next = NULL;
    //     if(parent!=NULL)
    //     {
    //         parent->next = curr;
    //     }
    //     else
    //     {
    //         head2 = curr;
    //     }
    //     parent = curr;
    //     cin>>temp2;
    // }
    node * result = obj.solution(head1,head2);
    if(result == NULL)
    {
        cout<<"No intersection";
    }
    else
    {
        cout<<result->data;
    }
}