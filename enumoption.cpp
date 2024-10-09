#include "enumoption.h"
#include <QStringList>

EnumOption::EnumOption(QStringList& listOptions, QObject *parent)
    : listOptions(listOptions), QObject{parent}
{}
