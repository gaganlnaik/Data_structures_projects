#include<iostream>
#include<iomanip>
#include "exceptions.h"

using namespace std;

template<class T>

class array1d   //1d array class
{   public:
    T *element;
    int siz;
    int len;
    array1d(int sz=1)
    {
        len = 0;
        siz = sz;
        element = new T[sz];

    }
    array1d<T> operator+ (array1d<T> temp)
    {
       if (siz!=temp.siz)
         throw SizeMismatch();
        array1d<T> sum(siz);
        for (int i = 0 ; i < siz ;i++)
            sum.element[i]=element[i] + temp.element[i];

        return sum;
    }

    array1d<T>& operator= (const array1d<T>& temp)
    {
       if (siz!=temp.siz)
            throw SizeMismatch();
        for (int i = 0 ; i < siz;i++)
            element[i]=temp.element[i];
        return *this;

    }

    T operator[] (int index)
    {
     if (index < 0 || index > siz)
         throw OutOfBounds();

        return element[index-1];
    }


    void insert_data(int k, const T x) // not needed in array 2d insertion
    {  if (k>len && k<siz+1)
          {

           element[k-1]=x;
        len++;}
        else if(k>siz)
            throw OutOfBounds();

       else
       {
        for (int i=len;i>k;i--)
            {
                element[i] = element [i-1];

            }

            element[k-1] = x;
            len++;
            }




    }

    void show_data()

    {
        for(int k=0;k<siz;k++)
            cout<<element[k]<<"   ";
    }

    array1d<T>& mem_resize(int col)  // from the 2d array
    {

        siz = col;
        delete []element;
        element = new T[siz];
        return *this;

    }



    ~array1d()
    {
        delete []element;
    }

};


/*
int main()
{try
{
    array1d<int> A(3),B(3),c(3);

    A.insert_data(1,1);
    cout<<A.len<<A.siz<<endl;
    A.insert_data(3,2);
    A.insert_data(2,3);
    B.insert_data(1,3);
    B.insert_data(2,2);B.insert_data(3,1);
    A.show_data();
    cout<<"-------------------------------"<<endl;
    B.show_data();


}
catch(exception &e)
    {
        cout<<e.what()<<endl;
    }
}

*/
