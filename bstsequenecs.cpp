#include<iostream>
#include <algorithm> 
#include <list> 
using namespace std;
struct node
{
    node *left;
    node *right;
    int data;
};

class bstsequences
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
    list<node*> levelorder(node *root,list<node*> arr[], int level)
    {
        if(root == NULL) return;
        arr[level].push_back(root);
        arr = levelorder(root->left,arr,level+1);
        arr = levelorder(root->right,arr,level+1); 
    }
    void permutation(list<node*> arr, int size, int n)
    {
        if (size == 1) 
        { 
            
        } 
    
        for (int i=0; i<size; i++) 
        { 
            permutation(arr,size-1,n); 
            if (size%2==1) 
                swap(arr[0], arr[size-1]); 
            else
                swap(arr[i], arr[size-1]); 
        } 
    }
};

int main()
{
    bstsequences obj;
    node *root = new node;
    root = NULL;
    root = obj.createtree(1);
    root->left = obj.createtree(2);
    root->right = obj.createtree(3);
    list<node*> arr[2];
    arr = obj.levelorder(root,arr,0);
    for(int i = 0; i<2; i++)
    {
        int len = arr[i].size();
        obj.permutation(arr[i],len,len);
    }
        
}