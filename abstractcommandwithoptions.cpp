#include "abstractcommandwithoptions.h"

AbstractCommandWithOptions::AbstractCommandWithOptions(QString name, CommandOption* commandOption, QObject *parent)
    : AbstractCommand{name, parent}, commandOption_(commandOption) {}

void AbstractCommandWithOptions::setCommandOption(CommandOption* commandOption){ commandOption_ = commandOption; }
