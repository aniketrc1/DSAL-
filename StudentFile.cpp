#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class student
{
    public:
    int roll;
    string name;
    string address;
    string divsion;



    void display()
    {
        cout<<"Name "<<name<<endl;
        cout<<"Roll "<<roll<<endl;
    }
};
void addstudent()
{

    ofstream file("fileAniket.txt",ios::app);
    student s;
    ofstream f;
    cout<<"Enter Roll Number"<<endl;
    cin>>s.roll;
    cout<<"Enter Name"<<endl;
    cin.ignore();
    getline(cin,s.name);

   file<<s.roll<< " "<<s.name<<endl;

}
void display()
{
    ifstream file("fileAniket.txt");
    student s;

    int searchRoll;

    cout<<"enter roll number"<<endl;
    cin>>searchRoll;

    bool found=false;
    while(file>>s.roll)
    {
        file.ignore();
        getline(file,s.name);

        if(s.roll==searchRoll)
        {
            s.display();
            found=true;
            break;
        }
       
    }

    if(!found) 
        cout<<"record not found"<<endl;
    file.close();
}
void delet()
{
    ifstream file("fileAniket.txt");
    ofstream temp("temp.txt");

    int number;
     cout<<"enter roll number to delete"<<endl;
     cin>>number;
      student s;
      bool found=false;
     while(file>>s.roll)
     {
        file.ignore();
        getline(file,s.name);

        if(number==s.roll)
        {
            found=true;
        }
        else
        {
            temp<<s.roll<<" "<<s.name<<endl;
        }

     }

     if(!found)
     {
        cout<<"Record not found"<<endl;
     }
     else{
        cout<<"Record deleted"<<endl;
     }

     file.close();
     temp.close();
     remove("fileAniket.txt");
     rename("temp.txt","fileAniket.txt");

}

int main()
{


    cout<<"---------------------"<<endl;
    cout<<"Student System"<<endl;
    cout<<"1)add Student"<<endl;
    cout<<"2)delete student"<<endl;
    cout<<"3)display student"<<endl;
    cout<<"4)exit "<<endl;

    int choice;

    

      bool flag=true;
      while(flag)
      {
        cout<<"enter your choice"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
             addstudent();
            break;
         case 2:
             delet();
             break;
         case 3:
             display();
             break;
         case 4:
              flag=false;
              break;
        
        default:
        cout<<"enter Correct choice"<<endl;
             
            break;
        }
      }



   
}