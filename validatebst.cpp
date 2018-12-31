#include<iostream>
#include<cmath>
using namespace std;
struct node
{
    node *left;
    node *right;
    int data;
};

class validatebst
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
    int c = 1;
    bool solution(node *root)
    {
        if(root==NULL) return true;
        if(root->left != NULL && root->data>=root->left->data) 
        {
            solution(root->left);
        }
        else if(root->left != NULL && root->data<root->left->data) 
        {
            c = 0;
            return false;
        }
        if(root->right != NULL && root->data<root->right->data)  
        {
            solution(root->right);
        }
        else if(root->right != NULL && root->data>=root->right->data) 
        {
            c = 0;
            return false;
        }
        if (c == 0) return false;
        else return true;
    }
};



int main()
{
    validatebst obj;
    node *root = new node;
    root = NULL;
    root = obj.createtree(4);
    root->left = obj.createtree(2);
    root->left->left = obj.createtree(1);
    // root->left->left->left = obj.createtree(7);
    // root->left->left->left->left = obj.createtree(8);
    // root->left->left->left->left->left = obj.createtree(8);
    root->left->right = obj.createtree(3);
    root->right = obj.createtree(6);
    root->right->left = obj.createtree(5);
    //root->right->right = obj.createtree(7);
    bool result = obj.solution(root);
    cout<<result;
}