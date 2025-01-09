#include "getcommand.h"

QString GetCommand::getSQL() {
    return QString("SELECT * FROM %1").arg(this->listFilter);
}
