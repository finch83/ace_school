class cString
{
public:
    cString() : pData(nullptr) {}
    cString(int _size)
    {
        pData = new char(_size);
    }

    ~cString() { delete pData; }


private:
    char* pData;
};

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

