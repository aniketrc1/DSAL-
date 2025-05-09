#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
       data=val;
       left=nullptr;
       right=nullptr;
    }
};
Node* insert(Node* root,int val)
{
    if(root==nullptr)
        return new Node(val);
    if(root->data<=val)
    {
        root->right=insert(root->right,val);
       
    }else
    {
        root->left=insert(root->left,val);
    }
    return root;
       

}


void inoder(Node* root)
{
   if(root==nullptr)
      return;
    inoder(root->left);
    cout<<root->data<<" ";
    inoder(root->right);
   
}
int  min(Node* root)
{
    if(root==nullptr)
    {
        cout<<"tree is empty";
        return -1;

    }
  Node* temp=root;
  while(temp->left!=nullptr)
  {
    temp=temp->left;

    
  }
  return temp->data;     
}

bool search(Node* root,int key)
{
  if(root==nullptr)
      return false;
  if(root->data==key)
  {
    return true;
  }
  else if(root->data<=key)
      return search(root->right,key);
  else
     return search(root->left,key);

}
void mirror(Node* root)
{
   if(root==nullptr)
        return;
    Node* temp=root->left;
    root->left=root->right;
    root->right=root->left;

    mirror(root->left);
    mirror(root->right);
}
int longestpath(Node* root)
{
  if(root==nullptr)
      return 0;
   int leftHeight=longestpath(root->left);
   int rightHeight=longestpath(root->right);
   
   return (leftHeight>rightHeight?leftHeight:rightHeight)+1;
}

int main()
{
  int values[]= {50, 30, 20, 40, 70, 60, 80};
Node* root=nullptr;

  for(int i=0;i<7;i++)
  {
       root=insert(root,values[i]);
  }

//   inoder(root);
//   cout<<endl;
//  cout<< min(root);

 cout<<search(root,100);

 cout<<search(root,80);

 cout<<"before mirrior"<<endl;

inoder(root);


mirror(root);
cout<<"After mirror"<<endl;

inoder(root);


cout<<"longest path"<<longestpath(root);

}