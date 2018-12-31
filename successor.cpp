#include<iostream>
#include<cmath>
using namespace std;
struct node
{
    node *left;
    node *right;
    node *parent;
    int data;
};

class validatebst
{
    public:
    node* createtree(int val,node* p)
    {
        node *root = new node;
        root->data = val;
        root->left = NULL;
        root->right = NULL;
        root->parent = p;
        return root;
    }
    node* solution(node *temp)
    {
        if(temp==NULL) return NULL;
        if(temp->right!=NULL)
        {
            node *curr = temp->right;
            node * prev = new node;
            while(curr!=NULL)
            {
                prev = curr;
                curr = curr->left;
            }
            return prev;
        }
        node *p = temp->parent;
        node *curr = temp;
        while(p!=NULL && curr!=p->left)
        {
            curr = p;
            p = p->parent;
        }
        return p;
    }
};

int main()
{
    validatebst obj;
    node *root = new node;
    root = NULL;
    root = obj.createtree(4,NULL);
    root->left = obj.createtree(2,root);
    root->left->left = obj.createtree(1,root->left);
    // root->left->left->left = obj.createtree(7);
    // root->left->left->left->left = obj.createtree(8);
    // root->left->left->left->left->left = obj.createtree(8);
    root->left->right = obj.createtree(3,root->left);
    root->right = obj.createtree(6,root);
    root->right->left = obj.createtree(5,root->right);
    root->right->right = obj.createtree(7,root->right);
    node* result = obj.solution(root->right->right);
    if(result == NULL) cout<<"NULL"<<"\n";
    else
    cout<<result->data<<"\n";
}