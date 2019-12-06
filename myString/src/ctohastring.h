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

    void clear();
    void resize();
    size_t getSize();
    size_t getCapacity();

    friend std::ostream& operator<<(std::ostream&, const ctohaString&);
    friend std::istream& operator>>(std::istream&, ctohaString&);

private:
    static constexpr size_t mnInitCapacity = 255;
    static constexpr size_t mnInitSize = 0;

    size_t  mnSize;
    size_t  mnCapacity;

    char*   mpData;
};

#endif // CTOHASTRING_H
