#include <iostream>
using namespace std;
#include "Library.h"

int main()
{
    cout << "--- WELCOME TO THE LIBRARY ---\n";
    Library obj;
    try
    {
        obj.Interface();
    }
    catch (const char* str)
    {
        cout << "\n!!! ERROR !!!" << str;
        obj.Interface();
    }
    catch (...)
    {
        cout << "\n!!! ERROR !!!";
        obj.Interface();
    }
}