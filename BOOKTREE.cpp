#include<iostream>
using namespace std;
class Node
{
    public:
    string name;
    Node* child;
    Node* sibling;

    Node(string n)
    {
        name=n;
        child=nullptr;
        sibling=nullptr;
    }
    
};
Node* addchild(Node* parent,string childname)
{
    Node* newnode=new Node(childname);

    if(parent->child==nullptr)
    {
       parent->child=newnode;
    }else{
        
Node* temp=parent->child;
 while(temp->sibling!=nullptr)
 {
    temp=temp->sibling;
 }
 temp->sibling=newnode;




    }
    return newnode;


} 
void display(Node* root,int level=0)
{
    if(root==nullptr)
         return;

        
    

    for(int i=0;i<level;i++)
    {
        cout<<" ";
    }
    cout<<root->name<<endl;
    display(root->child,level+1);
    display(root->sibling,level);

}



int main()
{
    Node* root=new Node("Book");

     Node* chp1=addchild(root,"chp1");
     Node* chp2=addchild(root,"chp2");
     Node* chp3=addchild(root,"chp3");


     Node* sec1=addchild(chp1,"sec1");

      cout<<"name"<<chp1->name<<endl;
      cout<<"chuild"<<chp1->child->name<<endl;
      cout<<"Sibling"<<chp1->sibling->name<<endl;
    
}

