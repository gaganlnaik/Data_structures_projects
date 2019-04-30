#include <iostream>


using namespace std;

template <class T>
class Node
{
public:
T data;
Node <T>*link;
};

template <class T>
class stack_linklist
{
public:
    Node<T> *first;
    int len;
    stack_linklist()        //constructor
    {
        len=0;first=0;
    }
     ~stack_linklist()
    {
        Node<T> *temp;
        while(first)
        {
            temp = first->link;
            delete first;
            first = temp;
        }
    }

     bool isempty(){
        return len==0;}

    void push(const T & value)
    {
        Node<T> *temp1=new Node<T>;
//        if (!temp1)
//            throw NoMemory();
        temp1->data=value;
        temp1->link=first;
        first=temp1;

        len++;

        }

    T& pop()
    {
        if(!isempty())
        {
            Node<T> *temp=first;
            first=temp->link;
            len--;
            return temp->data;
        }
    }

    string reverse_string() {
		string temp="";
		while(len!=0)
        {
			temp=temp+pop();
        }
		return temp;
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



};

//int main()
//{
//    stack_linklist<int> s1;
//    s1.push(1);
//    s1.push(2);
//    s1.push(3);
//    s1.push(4);
//    s1.display();
//}
//int main()
//{
//    try
//    {
//       linklist<int> l1;
//       l1.push(1);
//       l1.push(2);
//       l1.push()
//       l1.insert_node(1,2);
//       l1.insert_node(2,4);
//       l1.insert_node(3,6);
//       l1.insert_node(4,6);
//       l1.display();
//       l1.reverse();
//       cout<<"-------------"<<endl;
//       l1.display();
//
//    }
//
//    catch(exception &e)
//    {
//        cout<<e.what()<<endl;
//    }
//
//}
