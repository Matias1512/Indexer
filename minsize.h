#ifndef MINSIZE_H
#define MINSIZE_H

#include <QObject>
#include "option.h"

class MinSize : public Option
{
public:
    MinSize(const int& number, const QString& unit)
        : number(number), unit(unit) {}

    QString getSQL(bool isTheLastOption) const override;

private:
    int number;
    QString unit;
};

#endif // MINSIZE_H
