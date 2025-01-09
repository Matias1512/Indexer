#ifndef COMMAND_H
#define COMMAND_H

#include <QString>
#include <QDebug>
#include <QObject>

class Command : public QObject
{
public:
    virtual ~Command() {}
    virtual QString getSQL() = 0;
};

#endif // COMMAND_H
