#include<iostream>
#include<fstream>
using namespace std;

class sett
{
    string userName,email,password;
    string name,mail,pass;
    fstream my_file;
public:
void login();
void signup();
void forgot();
}obj;

int main()
{
    char choice;
    do{
    cout<<"\n1-Login";
    cout<<"\n2-Sign up";
    cout<<"\n3-Forgot password";
    cout<<"\n4-Exit";
    cout<<"\nEnter your choice:";
    cin>>choice;

    switch(choice)
    {
    case '1':
        obj.login();
        break;
        case '2':
        obj.signup();
        break;
        case '3':
        obj.forgot();
        break;
        case '4':
            return 0;
        break;
        default:
            cout<<"Invalid selection...!";
    }}
    while(choice!='4');

}

 void sett::signup()
{
    cout<<"\n Enter your user name:";
    cin>>userName;
    cout<<"\n Enter your email:";
    cin>>email;
    cout<<"\n Enter your password:";
    cin>>password;
    ofstream my_file("details.txt");
    my_file<<userName<<"*"<<email<<"*"<<password<<endl;
    my_file.close();

}

void sett::forgot()
    {
        cout<<"Enter your Username:";
        cin>>name;
        cout<<"Enter your Email:";
        cin>>mail;

        ifstream my_file("details.txt");

             getline(my_file,userName,'*');
             getline(my_file,email,'*');
             getline(my_file,password,'\n');
             while(!my_file.eof())
             {
                if(userName==name)
                {
                    if(email==mail)
                    {
                        cout<<"\n Account found...!"<<endl;
                        cout<<"\n Your Password : "<<pass<<endl;
                    }
                    else{
                        cout<<"Not found...!\n";
                    }
                }
                  else{
                        cout<<"Not found...!\n";
                    }
    }
    }

    void sett::login()
     {
         string name,pass;
         cout<<"---------LOGIN-------"<<endl;
         cout<<"Enter your user name:"<<endl;

         cin>>name;
         cout<<"Enter your password"<<endl;
         cin>>pass;
         ifstream my_file("details.txt");

         while(!my_file.eof())
         {
             getline(my_file,userName,'*');
             getline(my_file,email,'*');
             getline(my_file,password,'\n');

             if(userName==name)
             {
                 if(password==pass)
                 {
                     cout<<"\n Account login successful...!";
                     cout<<"\n Welcome "<<userName;
                 }
                 else{
                    cout<<"Login failed..!";
                 }
             }

         }
         my_file.close();

     }
