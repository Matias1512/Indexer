#ifndef SEARCHCOMMAND_H
#define SEARCHCOMMAND_H

#include "command.h"

class SearchCommand : public Command
{
public:
    void execute() const override
    {
        qDebug() << "Executing Search Command";
    }
};

#endif // SEARCHCOMMAND_H
