#include<iostream>
using namespace std;
struct Node
{
    string keyword;
    string mean;
    Node* right;
    Node* left;

    Node(string key,string val)
    {
        keyword=key;
        mean=val;
        right=nullptr;
        left=nullptr;

    }
};
class dictonary
{
    Node* root;

    Node* insert(Node* root,string key,string val)
    {
        if(root==nullptr)
        {
            return new Node(key,val);
        }
       if(key<root->keyword)
        {
            root->left=insert(root->left,key,val);

        }
        else if(key>root->keyword){
           
            root->right=insert(root->right,key,val);
        }
        else{
            cout<<"keyword already exist"<<endl;
        }
        return root;
       
    }

    
    void inorder(Node* root)
    {
       
        if(root!=nullptr)
        {
           
          inorder(root->left);
          cout<<root->keyword<<":"<<root->mean<<endl;
          inorder(root->right);



        }
  

    }
    void reverseinorder(Node* root)
    {
        if(root!=nullptr)
        {
            reverseinorder(root->right);
            cout<<root->keyword<<":"<<root->mean<<endl;
            reverseinorder(root->left);


        }
    }
   Node* findmin(Node* root)
    {
        Node* temp=root;
        while (temp!=nullptr)
        {
           temp=temp->left;
        }
       return temp;
        
    }
    Node* dele(Node* root,string key)
    {
        if(root==nullptr) return root;

        if(key<root->keyword)
             root->left=dele(root->left,key);
        else if(key>root->keyword)
              root->right=dele(root->right,key);
        else
        {
            if(root->right==nullptr)
            {
                Node* temp=root->left;
                delete root;
                return temp;
            }
            if(root->left==nullptr)
            {
                Node* temp=root->right;
                delete root;
                return temp;
            }
            Node* temp=findmin(root->right);
            root->keyword=temp->keyword;
            root->mean=temp->mean;
           root->right=dele(root->right,temp->keyword);


        }
        return root;
    }
    Node* search(Node*root,int& count,string key)
    {
        
        
        while (root!=nullptr)
        {
            count++;
            if(root->keyword==key)
            {
                return root;
            }
            else if(key<root->keyword)
                root=root->left;
            else
               root=root->right;
                  
           
        }

        return nullptr;
        



    }

    public:
    void update(string key,string val)
    {
        int count=0;
        Node* temp=search(root,count,key);

        if(temp!=nullptr)
        {
            temp->mean=val;
            cout<<"keyword update sucessfully"<<endl;
        }
        else
        {
            cout<<"keyword Not found"<<endl;
        }

        
    }
  
   
    
    dictonary()
    {
        root=nullptr;
    }
    void add(string key,string mean)
    {
       root= insert(root,key,mean);
    }
    void display()
    {
        cout<<"dictonary data "<<endl;
        inorder(root);
    }
    void reverse()
    {

        cout<<"dictonary data  in reverse"<<endl;
        reverseinorder(root);

    }
    void deleteKeyword(string key) {
        root = dele(root, key);
    }
    void findkeyword(string key)
    {
        int comp=0;
        Node* temp=search(root,comp,key);
        if(temp!=nullptr)
        {
            cout<<"found :"<<temp->keyword<<" :: "<<temp->mean<<"aftre "<<comp<<"comparsion found"<<endl;
        }
        else
        {
            cout<<"NOT found :"<<"aftre "<<comp<<"comparsion "<<endl;
        }
    }
   
};
int main()
{
    dictonary d;

    cout<<"1)add  "<<endl;
    cout<<"2)delete  "<<endl;
    cout<<"3)update "<<endl;
    cout<<"4)find "<<endl;
    cout<<"5)exit "<<endl;

    cout<<endl;
    bool is=true;
    while (is)
    {
        cout<<"enter choice";
        int ch;
        cin>>ch;
        cin.ignore();
        string key,data;

        switch(ch)
        {
        case 1:
            
             cout<<"enter keyword "<<endl;
             getline(cin,key);
             cout<<"enter menaing "<<endl;
             getline(cin,data);
             d.add(key,data);
            break;
        case 2:
             cout<<"enter keyword to be deletd"<<endl;
             getline(cin,key);
             break;
     case 3:
             cout << "Enter keyword to update: ";
             cin >> key;
             cout << "Enter new meaning: ";
             cin.ignore();
             getline(cin, data);
           
             break;
        default:
            break;
        }
        
    }
    




}
