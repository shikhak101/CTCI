#include<iostream>
using namespace std;
struct node
{
    node *left;
    node *right;
    int data;
};

class minimaltree
{
    public:
    node* createmintree(int arr[], int start, int end)
    {
        if(start>end) return NULL;
        node *n = new node;
        int mid = (start+end)/2;
        n->data = arr[mid];
        n->left = createmintree(arr,start,mid-1);
        n->right = createmintree(arr,mid+1,end);
        return n;
    }
    void print(node *curr)
    {
        if(curr != NULL)
        {
            cout<<curr->data;
            cout<<"--";
            print(curr->left);
            print(curr->right);
        }
    }
};

int main()
{
    minimaltree obj;
    cout<<"Enter array size : ";
    int n;
    cin>>n;
    cout<<"ENter array values : ";
    int arr[n];
    for(int i = 0; i<n ; i++)
    {
        cin>>arr[i];
    }
    node *head =new node;
    head = obj.createmintree(arr,0,n-1);
    obj.print(head);
}