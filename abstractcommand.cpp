#include "abstractcommand.h"

AbstractCommand::AbstractCommand(QString name, QObject *parent)
    : QObject{parent}, name_(name) {}

void AbstractCommand::setName(const QString &name) { name_ = name; }
