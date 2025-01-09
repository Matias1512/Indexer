#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include <QObject>
#include "Command.h"

class AddCommand : public Command
{
    Q_OBJECT

private:
    QString listFilter;
    QString pathFolder;
    QList<QString> typeListSpec;

public:
    // Constructeur pour initialisation avec un chemin de dossier
    AddCommand(const QString& listFilter, const QString& pathFolder)
        : listFilter(listFilter), pathFolder(pathFolder), typeListSpec() {}

    // Constructeur pour initialisation avec une liste spécifique
    AddCommand(const QString& listFilter, const QList<QString>& typeListSpec)
        : listFilter(listFilter), pathFolder(""), typeListSpec(typeListSpec) {}

    // Implémentation de la méthode virtuelle
    virtual QString getSQL() override;
};

#endif // ADDCOMMAND_H
