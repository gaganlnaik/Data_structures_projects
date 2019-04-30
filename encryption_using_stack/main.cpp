#include <iostream>
#include<string>
#include "stack.cpp"
#include "stack_linked_list.cpp"
#include <typeinfo>
string x,y;         //global variable
using namespace std;
class enc_dec
{
    int count=0;

    public:
    string encryption()
    {
        stack_linklist<char> a=stack_linklist<char>();
        char temp;
        string message;
        cout<<"Enter the message "<<endl<<"-------------------------------------"<<endl;
        getline(cin,message);
        count=message.length();
        cout<<"Enter the secret key for your message, which is of type integer"<<endl;
        int shift;
        cin>>shift;

        for(int i=0;i<count;i++)
            {
            temp=message[i];
            temp=temp+shift;
            a.push(temp);
            }
        return a.reverse_string();


    }

    string decryption(string enc_message)
    {  cout<<"Enter the secret key"<<endl;
       int key;
       cin>>key;

       stack_linklist<char> b=stack_linklist<char>();
        char temp;
        for(int i=0;i<count;i++)
            {
            temp=enc_message[i];
            temp=temp-key;
            b.push(temp);
            }
        return b.reverse_string();
    }
};



int main()
{

    enc_dec test;
    x=test.encryption();
    cout<<"-------------------------------------"<<endl<<"Encrypted message"<<endl;
    cout<<x<<endl;
    cout<<"-------------------------------------"<<endl;
    y=test.decryption(x);
    cout<<"Decrypted message"<<endl;
    cout<<y<<endl;
    cout<<"--------------------------------------"<<endl;
    return 0;

    }


