#ifndef PUSHCOMMAND_H
#define PUSHCOMMAND_H

#include <QObject>
#include "abstractcommandwithoptions.h"

class PushCommand : public AbstractCommandWithOptions
{
public:
    PushCommand(QString name, CommandOption* commandOption, QObject *parent = nullptr);
};

#endif // PUSHCOMMAND_H
