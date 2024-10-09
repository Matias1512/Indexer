#ifndef CLEARCOMMAND_H
#define CLEARCOMMAND_H

#include <QObject>
#include "abstractcommandwithoptions.h"

class ClearCommand : public AbstractCommandWithOptions
{
public:
    ClearCommand(QString name, CommandOption* commandOption, QObject *parent = nullptr);
};

#endif // CLEARCOMMAND_H
