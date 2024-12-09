#ifndef COMMAND_H
#define COMMAND_H

#include <QString>
#include <QDebug>
#include <QObject>

class Command : public QObject
{
public:
    virtual ~Command() {}
    virtual void execute() const = 0; // Méthode virtuelle pure
};

#endif // COMMAND_H
