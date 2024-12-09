#ifndef GETCOMMAND_H
#define GETCOMMAND_H

#include <QObject>
#include "Command.h"

class GetCommand : public Command
{
    Q_OBJECT
public:
    void execute() const override
    {
        qDebug() << "Executing Get Command";
    }
};

#endif // GETCOMMAND_H
