#ifndef ABSTRACTCOMMANDWITHOPTIONS_H
#define ABSTRACTCOMMANDWITHOPTIONS_H

#include <QObject>
#include "abstractcommand.h"
#include "commandoption.h"

class AbstractCommandWithOptions : public AbstractCommand
{
    Q_OBJECT

public:
    explicit AbstractCommandWithOptions(QString name, CommandOption* commandOption, QObject *parent = nullptr);

    void setCommandOption(CommandOption* commandOption);

private:
    CommandOption* commandOption_;

};

#endif // ABSTRACTCOMMANDWITHOPTIONS_H
