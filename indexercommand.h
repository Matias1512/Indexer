#ifndef INDEXERCOMMAND_H
#define INDEXERCOMMAND_H

#include <QObject>
#include "Command.h"

class IndexerCommand : public Command
{
    Q_OBJECT
public:
    void createDatabase();
    void indexDirectory(const QString &path);
    void printDatabaseContents();
};

#endif // INDEXERCOMMAND_H
