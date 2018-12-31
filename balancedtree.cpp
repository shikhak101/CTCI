#include<iostream>
#include<cmath>
using namespace std;
struct node
{
    node *left;
    node *right;
    int data;
};

class balancedtree
{
    public:
    int provedfalse = 0;
    int solution(node *root)
    {
        int ht_left=0,ht_right=0;
        if(root == NULL) return -1;
        ht_left = solution(root->left)+1;
        ht_right = solution(root->right)+1;
        int diff = ht_left - ht_right;
        if(abs(diff) > 1)
        {
            //cout<<"Proved false. diff = "<<diff;
            provedfalse = 1;
        }        
        int ht;
        if(provedfalse == 1) return -2;
        if(ht_left>ht_right) ht = ht_left;
        else ht = ht_right;
        return ht;
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
    balancedtree obj;
    node *root = new node;
    root = NULL;
    root = obj.createtree(1);
    root->left = obj.createtree(2);
    root->left->left = obj.createtree(3);
    root->left->left->left = obj.createtree(7);
    root->left->left->left->left = obj.createtree(8);
    // root->left->left->left->left->left = obj.createtree(8);
    root->left->right = obj.createtree(4);
    root->right = obj.createtree(5);
    root->right->left = obj.createtree(6);
    int result = obj.solution(root);
    if(result == -2) cout<<"Not a balanced tree";
    else cout<<"Balanced tree";
}