#ifndef GETCOMMAND_H
#define GETCOMMAND_H

#include <QObject>
#include "abstractcommandwithoptions.h"

class GetCommand : public AbstractCommandWithOptions
{
public:
    explicit GetCommand(QString name, CommandOption* commandOption, QObject *parent = nullptr);
};

#endif // GETCOMMAND_H
