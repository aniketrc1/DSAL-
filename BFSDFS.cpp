#include<iostream>
using namespace std;
#define MAX 6
struct Node
{
  int data;
   Node* next;
};

class Graph
{
     
    public:

int f;
int r;
int q[100];
   
int v;
   Node** adj;
   Graph(int v)
   {
    f=-1;
    r=-1;
    this->v=v;
     adj=new Node*[v];

     for(int i=0;i<=v;i++)
     {
        adj[i]=nullptr;
     }
   }

Node* creat(int data)
{
    Node* newnode=new Node();
    newnode->data=data;
    newnode->next=nullptr;
    return newnode;
}


void adedge(int u,int v)
{
    Node* newnode=creat(v);
    newnode->next=adj[u];
    adj[u]=newnode;


  newnode=creat(u);
  newnode->next=adj[v];
  adj[v]=newnode;
}

// void addEdge(int u, int v) {
//     // Add edge from u to v
//     Node* newNode = create(v);
//     newNode->next = adj[u];
//     adj[u] = newNode;

//     // Add edge from v to u (since it's an undirected graph)
//     newNode = create(u);
//     newNode->next = adj[v];
//     adj[v] = newNode;
// }



void printgraph()
{

    for(int i=0;i<v;i++)
    {
      cout<<"vertex "<<i<<" --> ";

      Node* temp=adj[i];

      while(temp!=nullptr)
      {
       cout<< temp->data<<" ";
        temp=temp->next;
      }

      cout<<endl;

    }

}


void bfs(int start)
{

    bool visted[v];
    for (int i=0;i<v;i++)
    {
        visted[i]=false;
    }
    
     visted[start]=true;
     f=r==0;

    q[r]=start;

    cout<<"tarversing start form "<<start<<" ";

    while(f<=r)
    {
        
        int current=q[f++];

        cout<<current<<" ";
        Node* temp=adj[current];
        while(temp!=nullptr)
        {
            int adjvertex=temp->data;
            if(!visted[adjvertex])
            {
                visted[adjvertex]=true;
                r++;
                q[r]=adjvertex;
            }
            temp=temp->next;
        }
    
    }



}
        

        

      

   

  




};

int graph[MAX][MAX];
bool visited[MAX];
int stac[MAX];
int top=-1;
int nodes=5;

bool isempty()
{
    if(top==-1)
       return true;
    else
       return false;
}
void push(int data)
{
    stac[++top]=data;
}
int pop()
{
    return stac[top--];
}

void matrix()
{
    cout<<"enter distance ";
    for(int i=0;i<=nodes;i++)
    {
        for(int j=1+i;j<=nodes;j++)
        {
            cout<<"Enter distence from "<<i<<" to "<<j<<endl;
            cin>> graph[i][j];
        }
    }
}
void print()
{
    for(int i=0;i<=nodes;i++)
    {
        for(int j=0;j<=nodes;j++)
        {
             cout<<graph[i][j]<<" ";
           
        }
        cout<<endl;
    }
}
void dfs(int start)
{
    push(start);

    while(!isempty())
    {
        int node=pop();
        if(!visited[node])
        {
             cout<<"nodes "<<node;
             visited[node]=true;
        }

        for(int i=nodes;i>0;i--)
        {
            if(graph[node][i]==1&&!visited[i])
            {
                push(i);
            }
        }
    }

}


int main()
{

matrix();
print();
dfs(1);

Graph g(5);
    g.adedge(1,2);
    g.adedge(2,4);
    g.adedge(4,3);
    g.adedge(3,1);
    g.printgraph();
    g.bfs(0);

}






