#ifndef INDEXERCOMMAND_H
#define INDEXERCOMMAND_H

#include <QObject>
#include <QString>
#include <QList>
#include "Command.h"

class IndexerCommand : public Command
{
    Q_OBJECT

public:
    // Enum pour les statuts de l'indexeur
    enum class indexStatus {
        STOPPED,   // L'indexation est arrêtée
        INDEXING,  // L'indexation est en cours
        PAUSED,    // L'indexation est en pause
        READY      // L'indexation est terminée
    };

private:
    indexStatus status; // Statut actuel de l'indexeur
    QList<QString> indexedFiles; // Liste des fichiers indexés

public:
    IndexerCommand();

    // Récupérer le statut actuel
    indexStatus getStatus() const;

    // Gérer l'indexation
    void createDatabase();
    void start();
    void stop();
    void pause();
    void resume();

    // Gestion des fichiers indexés
    void addIndexedFile(const QString &file);
    void displayIndexedFiles() const;

    // Gestion de la base de données
    void printDatabaseContents();
};

#endif // INDEXERCOMMAND_H
