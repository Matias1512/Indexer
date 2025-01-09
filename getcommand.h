#ifndef GETCOMMAND_H
#define GETCOMMAND_H

#include <QObject>
#include "Command.h"

class GetCommand : public Command
{
    Q_OBJECT

private:
    QString listFilter;

public:
    GetCommand(const QString& listFilter)
        : listFilter(listFilter){}
    virtual QString getSQL() override;

    QString getListFilter() const { return listFilter; }

    void setListFilter(const QString& value) { listFilter = value; }

};

#endif // GETCOMMAND_H
