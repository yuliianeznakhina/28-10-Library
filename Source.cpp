#include <iostream>
using namespace std;
#include "Library.h"

int main()
{
    cout << "--- WELCOME TO THE LIBRARY ---\n";
    Library obj;
    while (true) {
        try
        {
            obj.Interface();
        }
        catch (const char* str)
        {
            cout << "\n!!! ERROR !!!" << str;
        }
        catch (...)
        {
            cout << "\n!!! ERROR !!!";
        }
    }
}