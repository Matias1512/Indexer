#include "getcommand.h"

GetCommand::GetCommand(QString name, CommandOption* commandOption, QObject *parent)
    : AbstractCommandWithOptions{name, commandOption, parent}
{}
