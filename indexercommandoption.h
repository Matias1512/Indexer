#ifndef INDEXERCOMMANDOPTION_H
#define INDEXERCOMMANDOPTION_H

#include <QObject>
#include "enumoption.h"

class IndexerCommandOption : public EnumOption
{
    Q_OBJECT
public:
    explicit IndexerCommandOption(QStringList listOptions, QObject *parent = nullptr);
};

#endif // INDEXERCOMMANDOPTION_H
