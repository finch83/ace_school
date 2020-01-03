#include "ctohastring.h"

size_t const ctohaString::kDefaultSize = 0;
size_t constexpr ctohaString::kDefaultCapacity = 255;

//Default c-tor
ctohaString::ctohaString() :
    mnSize{kDefaultSize},
    mnCapacity{kDefaultCapacity},
    mpData{new char[kDefaultCapacity]}
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
    mnCapacity{_size >= kDefaultCapacity?
                   _size+kDefaultCapacity:
                   kDefaultCapacity},
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
        mnCapacity = (mnSize >= kDefaultCapacity) ?
            mnSize + kDefaultCapacity :
            kDefaultCapacity;
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
    if (mpData)
        delete [] mpData;
}

//
void ctohaString::clear()
{
    bzero(mpData, sizeof(mpData));
    mnSize = kDefaultSize;
    mnCapacity = kDefaultCapacity;
}

//
void ctohaString::reserve(size_t _nCapacity)
{
    if ( _nCapacity == mnCapacity  )
        return;

    if ( 0 == mnSize)
    {
        if (mpData) delete [] mpData;
        mnCapacity = _nCapacity;
        mpData = new char [mnCapacity];
        return;
    }

    char* tmpArr = new char[_nCapacity];
    mnSize = (_nCapacity < mnSize) ?
            _nCapacity :
            mnSize;
    strncpy(tmpArr, mpData, mnSize);
    if (mpData) delete [] mpData;
    mpData = tmpArr;
}

//
size_t ctohaString::getSize() const
{
    return mnSize;
}


//
size_t ctohaString::getCapacity() const
{
    return mnCapacity;
}

// output operator overload
std::ostream& operator<<(std::ostream& _os, const ctohaString& _cs)
{
    _os.write(_cs.mpData, _cs.mnSize);
//todo: check result

    return _os;
}

// input operator overload

std::istream& operator>>(std::istream& _is, ctohaString& _cs)
{
    _cs.clear();

    char tmpStr[255];
    _is >> tmpStr;
//todo: check result

    if ( strlen(tmpStr) >= _cs.getCapacity() )
    {
        _cs.reserve(strlen(tmpStr) + _cs.kDefaultCapacity);
    }

}

std::istream& operator>>(std::istream& _is, ctohaString& _cs)
{
    if ( 0 == _cs.getSize())
    {
        char tmpStr[255];
        _is >> tmpStr;

        if ( strlen(tmpStr) >= _cs.kDefaultCapacity )
        {
            delete [] _cs.mpData;
            _cs.mnCapacity = strlen(tmpStr) + _cs.kDefaultCapacity;
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
