#ifndef CLEARCOMMAND_H
#define CLEARCOMMAND_H

#include <QObject>
#include "Command.h"

class ClearCommand : public Command
{
    Q_OBJECT
public:
    void execute() const override
    {
        qDebug() << "Executing Clear Command";
    }
};

#endif // CLEARCOMMAND_H
