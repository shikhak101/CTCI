#include<iostream>
using namespace std;
struct node
{
    node *left;
    node *right;
    int data;
};

class firstcommonancestor
{
    public:
    node* createtree(int val)
    {
        node *root = new node;
        root->data = val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    node* solution(node *root, node *n1, node *n2)
    {
        if(root == n1 || root == n2 || root == NULL) return root;
        int n1onleft = node_exists(root->left,n1);
        int n2onleft = node_exists(root->left,n2);
        if(n1onleft != n2onleft)
        {
            return root;
        }
        node *n = new node;
        if(n1onleft == 1)
            n = root->left;
        else n = root->right;
        node* result =  solution(n,n1,n2);
        return result;
    }
    int node_exists(node *curr, node *n)
    {
        if(curr == NULL) return 0;
        if(curr == n) return 1;
        int l = node_exists(curr->left,n);
        int r = node_exists(curr->right,n);
        if(l==0 && r==0) return 0;
        return 1;

    }
};

int main()
{
    firstcommonancestor obj;
    node *root = new node;
    root = NULL;
    root = obj.createtree(1);
    root->left = obj.createtree(2);
    root->left->left = obj.createtree(4);
    root->left->left->left = obj.createtree(9);
    root->left->right = obj.createtree(5);
    root->left->right->left = obj.createtree(6);
    root->left->right->left->right = obj.createtree(7);
    root->right = obj.createtree(3);
    root->right->left = obj.createtree(8);
    node *n1 = root->left->left->left;
    node *n2 = root->right->left;

    // node *root1 = new node;
    // root1 = NULL;
    // root1 = obj.createtree(1);
    // root1->left = obj.createtree(2);
    // node *root2 = new node;
    // root2 = NULL;
    // root2 = obj.createtree(3);
    // root2->right = obj.createtree(4);
    // node *n1 = root1->left;
    // node *n2 = root
    node *result = obj.solution(root,n1,n2);
    if(result == NULL) cout<<"Error"<<"\n";
    else{
        cout<<n1->data<<"---"<<n2->data<<"--";
        cout<<result->data<<"\n";
    }
}