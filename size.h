#ifndef SIZE_H
#define SIZE_H

#include <QObject>
#include "option.h"

class Size : public Option
{
public:

    Size(const int& size)
        : size(size), maxSize(-1){}
    Size(const int& minSize, const int& maxSize)
        : size(minSize), maxSize(maxSize){}
    QString getSQL(bool isTheLastOption) const override;

private:
    int size;
    int maxSize;
};

#endif // SIZE_H
