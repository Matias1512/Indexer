#ifndef COMMANDOPTION_H
#define COMMANDOPTION_H

#include <QObject>
#include <QStringList>
#include "enumoption.h"

class CommandOption : public EnumOption
{
    Q_OBJECT
public:
    explicit CommandOption(QStringList listOptions, QObject *parent = nullptr);
};

#endif // COMMANDOPTION_H
