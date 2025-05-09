#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        next=nullptr;
    }
};
class chain
{

    Node* table[10];

    public:
    chain()
    {
        for(int i=0;i<10;i++)
        {
            table[i]=nullptr;
        }

    }
    int hash(int key)
    {
        return key%10;
    }

    void insert(int key)
    {
       int index=hash(key);
       Node* newnode=new Node(key);

       if(table[index]==nullptr)
       {
       
        table[index]=newnode;

       }
       else
       {
           newnode->next=table[index];
           table[index]=newnode;
       }


    }

    void display()
    {
        for(int i=0;i<10;i++)
        {
            cout<<i<<" ->";

            Node* temp=table[i];
            while(temp!=nullptr)
            {
                cout<<temp->data<<" -->"; 
                temp=temp->next;
            }
            cout<<" Null"<<endl;
        }
    }

    void search(int key)
    {
    int index=hash(key);
    int c=0;

    Node* temp=table[index];

    while (temp!=nullptr)
    {
        c++;
        if(temp->data==key)
        {
            cout<<"element found at "<<index<<" "<<"after comparsion " <<c<<endl;
            return;
        }

       

        temp=temp->next;
       
    }
    cout << "Number not found after " << c << " comparisons.\n";
    

    }

};
class hashtable
{
    public:
    int table[10];

    hashtable()
    {
      for(int i=0;i<10;i++)
              table[i]=-1;
    }

    int hash(int key)
    {
        return key%10;
    }
    void insertA(int key)
    {
        int index=hash( key);
         int startinedx=index;
            while(table[index]!=-1)
            {
                index=(index+1)%10;
               if(startinedx==index)
               {
                   cout<<"Table is full"; 
                   return;
               }
            }

         table[index]=key;

    }
    void display() {
        
        cout<<"Displaying Elements";
        for(int i=0;i<10;i++)
        {
            cout<<i<<" -> ";
            if(table[i]!=-1)
            {
               cout<<table[i];
            }
            else
               cout<<"Null";

        cout<<endl;

        }
    }


    void search(int key)
    {
      int index=hash(key);
      int startindex=index;

      int count=1;

         while(table[index]!=key)
         {
            index=(index+1)%key;
           count++;
            if(table[index]==-1||startindex==index )
            {

                 cout<<"element not found after copmparison of "<<count<<endl;
                 return;
            }
         }
         cout<<"found at index "<<index<<" after comparsion "<<count<<endl;
      

    }
};
int main()
{
    hashtable h;
    int n;
    cout<<"enter number of telphone to be inserted"<<endl;
    cin>>n;

    int num;

    cout<<"enter telphone number ";
    for(int i=0;i<n;i++)
    {

       cin>>num;
       h.insertA(num);
    }

    h.display();

    cout<<"enter number to be serched"<<endl;
    cin>>num;

      h.search(num);
    return 0;
}