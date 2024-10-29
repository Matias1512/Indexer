#ifndef INDEXERCOMMAND_H
#define INDEXERCOMMAND_H

#include <QObject>
#include "abstractcommand.h"
#include "indexercommandoption.h"

class IndexerCommand : public AbstractCommand
{
    Q_OBJECT
public:
    explicit IndexerCommand(QString name, IndexerCommandOption* indexerCommandOption, QObject *parent = nullptr);

    void setIndexerCommandOption(IndexerCommandOption* indexerCommandOption);

private:
    IndexerCommandOption* indexerCommandOption_;

};

#endif // INDEXERCOMMAND_H
