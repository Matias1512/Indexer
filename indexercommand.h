#ifndef INDEXERCOMMAND_H
#define INDEXERCOMMAND_H

#include <QObject>
#include "Command.h"

class IndexerCommand : public Command
{
    Q_OBJECT
public:
    void execute() const override
    {
        qDebug() << "Executing Indexer Command";
    }
};

#endif // INDEXERCOMMAND_H
