#include "clearcommand.h"

ClearCommand::ClearCommand(QString name, CommandOption* commandOption, QObject *parent)
    : AbstractCommandWithOptions{name, commandOption, parent}
{}
