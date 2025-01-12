#ifndef TYPE_H
#define TYPE_H

#include <QObject>
#include "option.h"

class Type : public Option
{
public:
    Type(const QList<QString>& listType) : listType(listType) {}

     QString getSQL(bool isTheLastOption) const override;

private:
    QList<QString> listType;
};

#endif // TYPE_H
