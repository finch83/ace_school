#include <iostream>
#include "ctohastring.h"

using namespace std;

void test()
{
    cout << "String> ";
    ctohaString cs3;

    cin >> cs3;
    cout << "Size: " << cs3.getSize() << endl;
    cout << "Capacity: " << cs3.getCapacity() << endl;
    cout << "Data: " << cs3 << endl;

}

int main()
{
    test();

return 0;
}

