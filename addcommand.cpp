#include "addcommand.h"

AddCommand::AddCommand(QString name, CommandOption* commandOption, QObject *parent)
    : AbstractCommandWithOptions{name, commandOption, parent}
{}
