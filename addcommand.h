#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include <QObject>
#include "Command.h"

class AddCommand : public Command
{
    Q_OBJECT
public:
    void execute() const override
    {
        qDebug() << "Executing Add Command";
    }
};

#endif // ADDCOMMAND_H
