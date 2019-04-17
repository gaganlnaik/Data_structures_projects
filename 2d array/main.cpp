#include<iostream>
#include<iomanip>
#include "array1d.cpp"


using namespace std;

template<class X>     //2d array class
class array2d
{
    int row;
    int col;
    array1d<X> *rows;
    public:



    array2d(int r=1 , int c=1)  //constructor of 2d class
    {
        row=r;
        col=c;
        rows = new array1d<X>[row];
        for (int s=0;s<row;s++)
            rows[s].mem_resize(col); // mem_resize is a function defined in array 1d class to resize the array1d into the size of col

    }

     void insert_val(int r_ele, int c_ele ,int val)
     {
         if (r_ele < 1 || c_ele <1 || r_ele > row || c_ele > col)   //check if user has givn -ve index
            throw OutOfBounds();

        else
            rows[r_ele-1].insert_data(c_ele,val);

     }

      array2d<X> operator+ (array2d<X> v)
    {
       if(row!= v.row || col!= v.col)
         throw SizeMismatch();

        else{

        array2d<X> sum(row,col);

        for (int i = 0 ; i < row ;i++)
            sum.rows[i] = rows[i]+ v.rows[i];

        return sum;

        }
    }

   /* array2d<X>& operator=(array2d<X> temp)
    {
        for(int i = 0; i < row ; i++)
            rows[i]=temp.rows[i];
        return *this;
    }

    array1d<X> operator[](int pos)
    {
        return rows[pos];
    }

*/

    void show_value() //display the 2d array
     {
        for(int i=0;i<=row-1;i++)
        {
            rows[i].show_data();
            cout<<endl;
        }

    }

};




int main()
{
    try
    {
    array2d<int> a(3,2);
   // a.insert_val(5,6,10);
     //a.insert_val(-1,-2,50);
    a.insert_val(1,1,10);
    a.insert_val(1,2,20);
    a.insert_val(2,1,30);
    a.insert_val(2,2,40);
    a.insert_val(3,1,50);
    a.insert_val(3,2,60);
    a.show_value();
cout<<"---------------------------------"<<endl;
    array2d<int> b(3,2);
   // b.insert_val(5,6,10);
    // b.insert_val(-1,-2,50);
    b.insert_val(1,1,1);
    b.insert_val(1,2,2);
    b.insert_val(2,1,3);
    b.insert_val(2,2,4);
    b.insert_val(3,1,5);
    b.insert_val(3,2,6);
    b.show_value();
    cout<<"----------------------"<<endl;

    array2d<int> c(3,2);
    c=a+b;

   c.show_value();
    }


    catch(exception &e)
    {
        cout<<e.what()<<endl;
    }



    return 0;
}
