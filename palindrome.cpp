#include<iostream>
#include<cmath>
using namespace std;
struct node
{
    node *next;
    string data;
};

class palindrome
{
    public:
    bool solution(node *head)
    {
        node *curr = head;
        node *currnext = new node;
        node *prev = new node;
        prev = NULL;
        int length = 0;
        while(curr!=NULL)
        {
            length++;
            curr = curr->next;
        }
        curr = head;
        node *mid = new node;
        node *breakpt = new node;
        for(int i = 0;i<length/2;i++)
        {
            breakpt = curr;
            curr = curr->next;
        }
        mid = curr;
        
        while(curr!=NULL)
        {
            currnext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currnext;
            
        }
        breakpt->next = prev;
        curr = head;
        for(int i = 0;i<length/2;i++)
        {
            curr = curr->next;
        }
        mid = curr;
        cout<<mid->data;
        node *temp = mid;
        curr = head;

        while(curr!=NULL)
        {
            cout<<curr->data;
            cout<<"->";
            curr = curr->next;
        }
        cout<<"\n";
        curr = head;
        while(curr!=mid)
        {
            if(curr->data == temp->data)
            {
                curr = curr->next;
                temp = temp->next;
            }
            else{
                return 0;
            }
        } 
        return 1;
    }
};

int main()
{
    string temp;
    palindrome obj;
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
    bool result = obj.solution(head);
    cout<<result;
}