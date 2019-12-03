#include <iostream>
#include <cstring>

using namespace std;

class cString
{
public:
    cString() :
        mnSize{mnInitSize},
        mnCapacity{mnInitCapacity},
        mpData{new char[(mnInitCapacity)]}
    {
        clear();
    }

    cString(size_t _size) :
        mnSize{_size},
        mnCapacity{_size >= mnInitCapacity?
                       _size+mnInitCapacity:
                       mnInitCapacity},
        mpData{new char[(mnSize)]}
    {
        clear();
    }

    cString(const char* _pSrcStr) :
        mnSize{mnInitSize},
        mnCapacity{mnInitCapacity},
        mpData{new char[(mnInitCapacity)]}
    {
        if (_pSrcStr)
        {
            if ( strlen(_pSrcStr) >= mnInitCapacity )
            {
                delete []mpData;
                mnCapacity = strlen(_pSrcStr) + mnInitCapacity;
                mpData = new char[mnCapacity];
                clear();
            }
            mnSize = strlen(_pSrcStr);
            strncpy(mpData, _pSrcStr, strlen(_pSrcStr));
            mnSize = strlen(_pSrcStr);
            mpData[mnSize] = '\0';
        }
        else
        {
            cout << "Empty pointer" << endl;
        }
    }

    ~cString() { delete [] this->mpData; }

    void clear()
    {
        bzero(mpData, sizeof(mpData));
        mnSize = mnInitSize;
        mnCapacity = mnInitCapacity;
    }

    int GetSize()
    {
        return mnSize;
    }

    int GetCapacity()
    {
        return this->mnCapacity;
    }

    friend ostream& operator<<(ostream& os, const cString& _cs)
    {
        os.write(_cs.mpData, _cs.mnSize);

        return os;
    }

    friend std::istream& operator>>(std::istream& is, cString& _cs)
    {
        if ( 0 == _cs.GetSize())
        {
            char tmpStr[255];
            is >> tmpStr;

            if ( strlen(tmpStr) >= _cs.mnInitCapacity )
            {
                delete [] _cs.mpData;
                _cs.mnCapacity = strlen(tmpStr) + _cs.mnInitCapacity;
                _cs.mpData = new char[_cs.mnCapacity];
                _cs.clear();
            }
            _cs.mnSize = strlen(tmpStr);
            strncpy(_cs.mpData, tmpStr, strlen(tmpStr));
            _cs.mnSize = strlen(tmpStr);
            _cs.mpData[_cs.mnSize] = '\0';
        }
        else
        {
            is >> _cs.mpData;
            _cs.mnSize = strlen(_cs.mpData);
            _cs.mpData[_cs.mnSize] = '\0';
        }

        return is;
    }


private:
    static constexpr size_t mnInitCapacity = 255;
    static constexpr size_t mnInitSize = 0;

    size_t  mnSize;
    size_t  mnCapacity;

    char*   mpData;
};


void test()
{
    cout << "String> ";
    cString cs3;
    cin >> cs3;
    cout << "Size: " << cs3.GetSize() << endl;
    cout << "Capacity: " << cs3.GetCapacity() << endl;
    cout << "Data: " << cs3 << endl;
}

int main()
{
    test();

return 0;
}

