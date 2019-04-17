#include <iostream>
#include <exception>

using namespace std;

//Class OutOfBounds inherited from Base Class exception
class OutOfBounds:public exception
{
    //what() function returns a null teminated sequence of characters
    public:
    const char* what() const throw()
    {
        return"Invalid Index";
    }
};

//Class NoMemory inherited from Base Class exception
class NoMemory:public exception
{
    //what() function returns a null terminated sequence of characters
    public:
    const char* what() const throw()
    {
        return"Out of Memory";
    }
};


