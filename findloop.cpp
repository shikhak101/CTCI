#include<iostream>
#include<cmath>
using namespace std;
struct node
{
    node *next;
    string data;
};

class findloop
{
    public:
    node* solution(node *head)
    {
        node *slowrun = head;
        node *fastrun = head;
        while(fastrun!=NULL && fastrun->next!=NULL)
        {
            slowrun = slowrun->next;
            fastrun = fastrun->next->next;
            if(slowrun == fastrun) break;
        }
        slowrun = head;
        if(fastrun==NULL || fastrun->next==NULL) return NULL;
        while(slowrun!=fastrun){
            slowrun = slowrun->next;
            fastrun = fastrun->next;
        }
        return slowrun;

    } 
};

int main()
{
    string temp;
    findloop obj;
    node *head = new node;
    node *curr1 = new node;
    node *curr2 = new node;
    node *curr3 = new node;
    node *curr4 = new node;
    node *curr5 = new node;
    node *curr6 = new node;
    head->data = 'a';
    head->next = curr1;
    curr1->data = 'b';
    curr1->next = curr2;
    curr2->data = 'c';
    curr2->next = curr3;
    curr3->data = 'd';
    curr3->next = curr4;
    curr4->data = 'e';
    curr4->next = curr5;
    curr5->data = 'f';
    curr5->next = head;

    // cout<<"Enter a value for linked list. Enter quit to stop";
    // node *parent = new node;
    // parent = NULL;
    // node *head = new node;
    // cin>>temp;
    // while(temp!="quit")
    // {
    //     int val = atoi(temp.c_str());
    //     node *curr = new node;
    //     curr->data = val;
    //     curr->next = NULL;
    //     if(parent!=NULL)
    //     {
    //         parent->next = curr;
    //     }
    //     else
    //     {
    //         head = curr;
    //     }
    //     parent = curr;
    //     cin>>temp;
    // }
    node *result = obj.solution(head);
    if(result == NULL) cout<<"No loop";
    else cout<<result->data;
}