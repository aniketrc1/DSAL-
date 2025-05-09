#include<iostream>
#include<fstream>
using namespace std;
struct emp
{
    string name;
    int id;
};

int count(const string& filename)
{
    fstream file(filename);

    int line=0;

    string temp;

    while(getline(file,temp))
    {
        line++;
    }
    file.close();
    
    return line;
    
}
void add()
{
    emp e;
    cout<<"enter emp id"<<endl;
    cin>>e.id;

    cout<<"enter emp name"<<endl;
    cin.ignore();
    getline(cin,e.name);

    ofstream data("data.txt",ios::app);
    data<<e.id<<" "<<e.name<<endl;
     data.close();


     int lines=count("data.txt");
     ofstream index("index.txt",ios::app);
     index<<e.id<<" "<<lines<<endl;
     index.close();

     cout<<"data added sucesfully"<<endl;


}

void display()
{
    int search;
    cout<<"enter emp id to search"<<endl;
    cin>>search;

    ifstream index("index.txt");
    int id,lineNo;
    bool found=false;

    while(index>>id>>lineNo)
    {
        
        if(id==search)
        {
            ifstream data("data.txt");
            string line;

            for(int i=1;i<=lineNo;i++)
            {
                getline(data,line);
            }
           found=true;
           cout<<"Empolyee found "<<line<<endl;
           data.close();
           break;
          
        }


    }
    if(!found)
    {
        cout<<"Empolyee not found"<<endl;
    }
}

void delet()
{
    int deletid;
    cout<<"Enter a id to be delet"<<endl;
    cin>>deletid;

    ifstream index("index.txt");
    ofstream temp("indextemp.txt");
      
    int id,lineno;
    int skipline=-1;
    bool found=false;
    
    while (index>>id>>lineno)
    {
        if(id==deletid)
        {
           found=true;
           skipline=lineno;
        }
        else
        {
            temp<<id<<" "<<lineno<<endl;
        }
        
    }
    index.close();
    temp.close();
    if(!found)
    {
        cout<<"emp is not prsent"<<endl;
        return;
    }

    ifstream data("data.txt");
    ofstream tempdata("tempdata.txt");
    string line;
    int linenum=1;
    while (getline(data,line))
    {
       if(skipline!=linenum)
       {
        tempdata<<line<<endl;
       }
       linenum++;
    }
    data.close();
    tempdata.close();

    remove("data.txt");
    remove("index.txt");
    rename("tempdata.txt","data.txt");
    rename("indextemp.txt","index.txt");
    cout << "Employee deleted successfully.\n";

}

int main()
{
   


   cout<<count("data.txt");

}