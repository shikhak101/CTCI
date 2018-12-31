#include<iostream>
#include<cmath>
using namespace std;
struct node
{
    node *next;
    int data;
};

class animalshelter
{
    public:
    node* push(node *head, int str)
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
    int top(node *temp)
    {
        return temp->data;
    }
};

int main()
{
    animalshelter obj;
    node* dog = new node;
    node* cat = new node;
    int order = 0;
    dog = NULL;
    cat = NULL;
    int i =0;
    while(i!=-1)
    {
        cout<<"Enter 1 to add dog, 2 to add cat, 3 to returnany, 4 to return dog, 5 to return cat, -1 to quit : ";
        cin>>i;
        if(i==1)
        {
            order++;
            dog = obj.push(dog,order);
            
        }
        else if(i == 2)
        {
            order++;
            cat = obj.push(cat,order);
            
        }
        else if(i == 3)
        {
            if(obj.top(dog) > obj.top(cat))
            {
                dog = obj.pop(dog);
            }
            else
            {
                cat = obj.pop(cat);
            }
        }
        else if(i == 4)
        {
            dog = obj.pop(dog);
        }
        else if(i == 5)
        {
            cat = obj.pop(cat);
        }
        node *curr = dog;
        while(curr!=NULL)
        {
            cout<<curr->data;
            cout<<"->";
            curr = curr->next;
        }
        cout<<"NULL";
        cout<<"\n";
        curr = cat;
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