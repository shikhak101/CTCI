#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>
using namespace std;
struct node
{
    node *next;
    int data;
};

class routebtwnode
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
            return NULL;
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
    bool route_dfs(int start,int end, vector<int> adj[], bool visited[])
    {
        node *curr = new node;
        curr = push(curr,start);
        
        while(curr!=NULL)
        {
            int u = top(curr);
            if(u==end){
                return true;
            }
            curr = pop(curr);
            visited[u] = true;
            int v;
            vector<int>::iterator i;
            for (i = adj[u].begin(); i!=adj[u].end(); i++)
            {
                if (visited[*i]!=true)
                    curr = push(curr,*i);
            }
        }
        
        return false;
    }

    void addEdge(vector<int> adj[], int u , int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

};

int main()
{
    routebtwnode obj;
    int no_of_vertices,no_of_edges;
    cout<<"Enter the number of vertices in the graph"<<endl;
    cin>>no_of_vertices;
    bool visited[no_of_vertices];
    for(int i = 0; i< no_of_vertices; i++)
    {
        visited[i] = false;
    }
    cout<<"Enter the number of egdes in the graph"<<endl;
    cin>>no_of_edges;
    vector<int> *adj = new vector<int>[no_of_vertices];
    for(int i=0; i<no_of_edges; i++)
    {
        cout<<"Enter start and end vertices : ";
        int u,v;
        cin>>u>>v;
        obj.addEdge(adj,u,v);
    }
    cout<<"Enter start vertex and end vertex : ";
    int start,end;
    cin>>start>>end;
    bool result = obj.route_dfs(start,end,adj,visited);
    cout<<result;
    
}