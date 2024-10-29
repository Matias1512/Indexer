#include "indexercommand.h"

IndexerCommand::IndexerCommand(QString name, IndexerCommandOption* indexerCommandOption, QObject *parent)
    : AbstractCommand{name, parent}, indexerCommandOption_(indexerCommandOption)
{}
