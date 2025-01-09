#include "AddCommand.h"

// Exemple d'implémentation de getSQL()
QString AddCommand::getSQL() {
    if (!pathFolder.isEmpty()) {
        return QString("INSERT INTO table %1 VALUES ('%2');")
        .arg(listFilter)
            .arg(pathFolder);
    } else if (!typeListSpec.isEmpty()) {
        return QString("INSERT INTO table %1 VALUES ('%2');")
        .arg(listFilter)
            .arg(typeListSpec.join(", "));
    }
    return "Invalid insert";
}
