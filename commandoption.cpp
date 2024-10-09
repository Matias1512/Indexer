#include "commandoption.h"

CommandOption::CommandOption(QStringList listOptions, QObject *parent)
    : EnumOption{listOptions, parent}
{}
