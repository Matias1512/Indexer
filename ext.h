#ifndef EXT_H
#define EXT_H

#include <QObject>
#include "option.h"

class Ext : public Option
{
public:
    Ext(const QList<QString>& extList) : extList(extList) {}
    QString getSQL(bool isTheLastOption) const override;

private:
    QList<QString> extList;
};

#endif // EXT_H
