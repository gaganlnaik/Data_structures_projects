#include <iostream>
#include "exceptions.h"

using namespace std;

template <class T>
class Node
{
public:
T data;
Node <T>*link;
};

template <class T>
class linklist
{
public:
    Node<T> *first;
    int len;
    linklist()        //constructor
    {
        len=0;first=0;
    }
     ~linklist()
    {
        Node<T> *temp;
        while(first)
        {
            temp = first->link;
            delete first;
            first = temp;
        }
    }

    //inset function
    void insert_node(int index,const T & value)
    {   if (index<1 || index-1>len)  //len not reqd
           throw OutOfBounds();
        Node<T> *temp1=new Node<T>;
        if (!temp1)
            throw NoMemory();
        temp1->data=value;
        temp1->link=0;
        if (len==0)
           first=temp1;

        else
        {
            if (index!=1)
            {
                Node<T> *temp2=first;
                for(int i=1;i<index-1;i++)
                  temp2=temp2->link;

                temp1->link=temp2->link;
                temp2->link=temp1;

            }
            else
            {
                temp1->link=first;
                first=temp1;
            }
        }

        len++;

        }

//Function to display linked list
       void display(){
        Node<T> *temp3=first;
        for (int i=0;i<len; i++)
            {
                cout<<temp3->data<<endl;
                temp3=temp3->link;
            }
        }


        //Function to reverse linked list
       void reverse()
    {
       Node<T> *current = first;
        Node<T> *previous = NULL;
        Node<T> *next = NULL;

        while(current!=NULL)
        {
            next = current->link;
            current->link = previous;
            previous = current;
            current = next;
        }
        first = previous;
    }


};


int main()
{
    try
    {
       linklist<int> l1;
       l1.insert_node(1,2);
       l1.insert_node(2,4);
       l1.insert_node(3,6);
       l1.insert_node(4,6);
       l1.display();
       l1.reverse();
       cout<<"-------------"<<endl;
       l1.display();

    }

    catch(exception &e)
    {
        cout<<e.what()<<endl;
    }

}
