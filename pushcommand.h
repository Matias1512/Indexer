#ifndef PUSHCOMMAND_H
#define PUSHCOMMAND_H

#include <QObject>
#include "Command.h"

class PushCommand : public Command
{
    Q_OBJECT
public:
    void execute() const override
    {
        qDebug() << "Executing Push Command";
    }
};

#endif // PUSHCOMMAND_H
