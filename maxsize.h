#ifndef MAXSIZE_H
#define MAXSIZE_H

#include <QObject>
#include "option.h"

class MaxSize : public Option
{
public:
    MaxSize(const int& number, const QString& unit)
        : number(number), unit(unit) {}

    QString getSQL(bool isTheLastOption) const override;

private:
    int number;
    QString unit;
};

#endif // MAXSIZE_H
