#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include <QObject>
#include "abstractcommandwithoptions.h"

class AddCommand : public AbstractCommandWithOptions
{
    Q_OBJECT
public:
    AddCommand(QString name, CommandOption* commandOption, QObject *parent = nullptr);
};

#endif // ADDCOMMAND_H
