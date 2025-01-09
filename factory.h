#ifndef FACTORY_H
#define FACTORY_H

#include "Command.h"
#include "searchcommand.h"
#include "indexercommand.h"
#include "getcommand.h"
#include "addcommand.h"
#include "pushcommand.h"
#include "clearcommand.h"

#include <QString>
#include <QHash>
#include <functional>

class Factory
{
public:
    /*
    static Command* createCommand(const QString &commandName)
    {
        if (commandName == "SEARCH")
            return new SearchCommand();
        else if (commandName == "INDEXER")
            return new IndexerCommand();
        else if (commandName == "GET")
            return new GetCommand();
        else if (commandName == "ADD")
            return new AddCommand();
        else if (commandName == "PUSH")
            return new PushCommand();
        else if (commandName == "CLEAR")
            return new ClearCommand();

        return nullptr; // Si la commande est invalide
    }
*/
};

#endif // FACTORY_H
