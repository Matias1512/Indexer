#ifndef FACTORY_H
#define FACTORY_H

#include "Command.h"
#include "searchcommand.h"
#include "indexercommand.h"
#include "getcommand.h"
#include "addcommand.h"
#include "pushcommand.h"
#include "clearcommand.h"
#include "token.h"

#include <QString>
#include <QHash>
#include <functional>

class Factory
{
public:
    static Command* createCommand(const QList<Token>& tokenList);
};

#endif // FACTORY_H
