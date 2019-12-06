#include "ctohastring.h"

//Default c-tor
ctohaString::ctohaString() :
    mnSize{mnInitSize},
    mnCapacity{mnInitCapacity},
    mpData{new char[mnInitCapacity]}
{
    clear();
}


//Copy c-tor
ctohaString::ctohaString(const ctohaString& _sc)
{
// todo
}

//
ctohaString::ctohaString(size_t _size) :
    mnSize{_size},
    mnCapacity{_size >= mnInitCapacity?
                   _size+mnInitCapacity:
                   mnInitCapacity},
               mpData{new char[mnSize]}
{
    clear();
}

//
ctohaString::ctohaString(const char* _pSrcStr)
{
    if (_pSrcStr)
    {
        mnSize = strlen(_pSrcStr);
        mnCapacity = (mnSize >= mnInitCapacity) ?
            mnSize + mnInitCapacity :
            mnInitCapacity;
        mpData = new char[mnCapacity];
        strncpy(mpData, _pSrcStr, mnSize);
        mpData[mnSize] = '\0';
    }
    else
    {
        std::cout << "Empty pointer" << std::endl;
    }
}

//
ctohaString::~ctohaString()
{
    if (this)
        delete [] mpData;
}


void ctohaString::clear()
{
    bzero(mpData, sizeof(mpData));
    mnSize = mnInitSize;
    mnCapacity = mnInitCapacity;
}

void ctohaString::resize()
{
//todo
}


size_t ctohaString::getSize()
{
    return mnSize;
}

//
size_t ctohaString::getCapacity()
{
    return mnCapacity;
}

// output operator overload
std::ostream& operator<<(std::ostream& _os, const ctohaString& _cs)
{
    _os.write(_cs.mpData, _cs.mnSize);

    return _os;
}

// input operator overload
std::istream& operator>>(std::istream& _is, ctohaString& _cs)
{
    if ( 0 == _cs.getSize())
    {
        char tmpStr[255];
        _is >> tmpStr;

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
        _is >> _cs.mpData;
        _cs.mnSize = strlen(_cs.mpData);
        _cs.mpData[_cs.mnSize] = '\0';
    }

    return _is;
}
