#include<iostream>
#include<cmath>
using namespace std;
struct node
{
    node *next;
    string data;
};

int capacity= 0;
int items = 0;
node* arr[1000];
int ind = 0;
class stackofplates
{
    public:
    node* push(node *head, string str)
    {
        if(items == capacity)
        {
            items = 0;
            ind++;
            node *temp = new node;
            temp->data = str;
            temp->next = NULL;
            head = temp;
            arr[ind] = head;
            items++;
            return head;
        }
        node *temp = new node;
        temp->data = str;
        temp->next = head;
        head = temp;
        arr[ind] = head;
        items++;
        return head;
    }
    node* pop(node *head)
    {
        
        cout<<ind;
        if(head == NULL)
        {
            cout<<"Nothing present";
        }
        else
        {
            cout<<"Entered correct";
            head = arr[ind];
            head = head->next;
            if(head == NULL && ind>0)
            {
                ind--;
                head = arr[ind];
            }
            else
            {
                arr[ind] = head;
            }
            
            items--;
        }
        return head;
    }
    node* popatindex(node *head)
    {
        if(head == NULL)
        {
            cout<<"nothing present";
        }
        else{
            head = head->next;
        }
        return head;
    }
};

int main()
{
    int i = 0;
    node *head = new node;
    head = NULL;
    cout<<"Enter capacity of each stack : ";
    cin>>capacity;
    while(i!=-1)
    {
        stackofplates obj;
        cout<<"Enter 1 to push , 2 to pop , 3 to popatindex, -1 to end : ";
        cin>>i;
        if(i == 1)
        {
            string str;
            cout<<"Enter value : ";
            cin>>str;
            head = obj.push(head,str);
            node *curr = new node;
            curr = arr[ind];
            int t = ind;
            while(t >= 0){
                while(curr!=NULL)
                {
                    cout<<curr->data;
                    cout<<"->";
                    curr = curr->next;
                }
                cout<<"NULL";
                cout<<"\n";
                t--;
                curr = arr[t];

            }
            
        }
        if(i == 2)
        {
            head = obj.pop(head);
            node *curr = new node;
            curr = arr[ind];
            int t = ind;
            while(t >= 0){
                while(curr!=NULL)
                {
                    cout<<curr->data;
                    cout<<"->";
                    curr = curr->next;
                }
                cout<<"NULL";
                cout<<"\n";
                t--;
                curr = arr[t];
            }
        }
        if(i==3)
        {
            cout<<"Enter index from where to pop";
            int j;
            cin>>j;
            arr[j] = obj.popatindex(arr[j]);
            node *curr = new node;
            curr = arr[ind];
            int t = ind;
            while(t >= 0){
                while(curr!=NULL)
                {
                    cout<<curr->data;
                    cout<<"->";
                    curr = curr->next;
                }
                cout<<"NULL";
                cout<<"\n";
                t--;
                curr = arr[t];
            }
        }
    }
}