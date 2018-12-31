
#include<iostream>
#include<cmath>
#include<list>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node *next;
};
int idx = 0;
class listofdepths
{
    public:
    void mysolution(node *curr, list<node*> arr[], int level)
    {
        
        if(curr == NULL) return;
        // cout<<curr->data<<"--";
        // cout<<level<<" level"<<"-------";
        node *l = new node;
        l->data = curr->data;
        l->next = NULL;
        arr[level].push_back(l);
        mysolution(curr->left,arr,level+1);
        mysolution(curr->right,arr,level+1);
    }

    node* createtree(int val)
    {
        node *root = new node;
        root->data = val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
};

int main()
{
    listofdepths obj;
    node *root = new node;
    root = NULL;
    root = obj.createtree(1);
    root->left = obj.createtree(2);
    root->left->left = obj.createtree(3);
    root->left->right = obj.createtree(4);
    root->right = obj.createtree(5);
    root->right->left = obj.createtree(6);
    list<node*> arr[5];
    obj.mysolution(root,arr,0); 
    for(int i = 0; i<3;i++)
    {
        list<node*> :: iterator j;
        for(j = arr[i].begin(); j!=arr[i].end(); j++)
        {
            node *t = *j;
            cout<<t->data<<"->";
        }
        cout<<"NULL";
        cout<<"\n";
    }
}