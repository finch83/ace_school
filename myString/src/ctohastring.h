#include <cstring>
#include <iostream>

#ifndef CTOHASTRING_H
#define CTOHASTRING_H

class ctohaString
{
public:
    ctohaString();
    ctohaString(const ctohaString&);
    ctohaString(size_t);
    ctohaString(const char*);
    ~ctohaString();

    void    clear();
    void    reserve(size_t);

    size_t  getSize() const;

    size_t  getCapacity() const;
    void    setCapacity(size_t);

    friend std::ostream& operator<<(std::ostream&, const ctohaString&);
    friend std::istream& operator>>(std::istream&, ctohaString&);

private:
    static const size_t kDefaultSize;
    static const size_t kDefaultCapacity;


    size_t  mnSize;
    size_t  mnCapacity;

    char*   mpData;
};

#endif // CTOHASTRING_H
