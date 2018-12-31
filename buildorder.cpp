#include<iostream>
#include<list>
#include<string>
using namespace std;
struct node
{
    node *next;
    int data;
};
int visited[100];
class buildorder
{
    public:
    string val="";
    
    void createdep(list<int> arr[],int u, int v)
    {
        arr[v].push_back(u);
    }
    string solution(int i, list<int> arr[])
    {
        if(visited[i] == 2) return "-1";
        if(visited[i] == 1) return val;
        if(visited[i] == 0)
        {
            visited[i] = 2;
            list<int> :: iterator j;
            for(j = arr[i].begin(); j != arr[i].end(); j++)
            {
                val = solution(*j,arr);
            }
            if(val == "-1") return "-1";
            visited[i] = 1;
            std::string s = std::to_string(i);
            val = val + s;
        }
        if(val == "-1") return "-1";
        return val;
    }
};

int main()
{
    buildorder obj;
    cout<<"Enter number of projects : ";
    int num;
    cin>>num;
    list<int> arr[num];
    for(int i = 0;i<num;i++)
    {
        visited[i]=0;
    }
    
    int u = 0;
    int v=0;
    while(u!=-1)
    {
        cout<<"Enter project dependencies and -1 for exit : ";
        cin>>u>>v;
        obj.createdep(arr,u,v);
    }

    string val;
    int i = 0;
    while(i<num)
    {
        val = obj.solution(i,arr);
        i++;
    }
    if (val=="-1") cout<<"Error"<<"\n";
    else cout<<val<<"\n";
}