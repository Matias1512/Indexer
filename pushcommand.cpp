#include "pushcommand.h"

PushCommand::PushCommand(QString name, CommandOption* commandOption, QObject *parent)
    : AbstractCommandWithOptions{name, commandOption, parent}
{}
